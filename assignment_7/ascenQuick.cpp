#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

bool readArrayFromFile(const std::string &filename, float arr[], int size) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return false;
  }
  
  int i = 0;
  float number;
  while (file >> number && i < size) {
    arr[i++] = number;
    if (file.peek() == ',') { //ignore comma
    }
  }

  file.close();
  return true;
}


int partition(float arr[], int low, int high) {
  float pivot = arr[high];  // pivot
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSort(float arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);   // recursive
    quickSort(arr, pi + 1, high);  // recursive
  }
}

int main() {
  const int SIZE = 1000;
  float arr[SIZE];
  std::string filename = "ascending_mostly_sorted.txt";
  
  if (!readArrayFromFile(filename, arr, SIZE)) {
    return 1;
  }

  // get start time
  clock_t start = clock();

  int low = 0;
  int high = SIZE - 1;

  // sorting algorithms
  quickSort(arr, low, high);

  // get stop time
  clock_t end = clock();

  // Calc delta time
  double deltaTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
  std::cout << "Time: " << deltaTime << " ms" << std::endl;
  return 0;
}