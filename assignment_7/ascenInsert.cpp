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

void insertionSort(float arr[], int size) {
  for (int i = 1; i < size; i++) {
    float key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) { //ascending
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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

  // sorting algorithms
  insertionSort(arr, SIZE);

  // get stop time
  clock_t end = clock();

  // Calc delta time
  double deltaTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
  std::cout << "Time: " << deltaTime << " ms" << std::endl;
  return 0;
}
