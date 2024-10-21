#include <cstdlib> 
#include <ctime>   
#include <iostream>

void generateRandomArray(float arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] =
        static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 1000.0));}
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

    quickSort(arr, low, pi - 1); //recusive 
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  const int SIZE = 1000;
  float arr[SIZE];
  srand(static_cast<unsigned>(time(0))); 
  generateRandomArray(arr, SIZE);        
  // get start time 
  clock_t start = clock();
  //sorting algorithms
  quickSort(arr, 0, SIZE - 1);

  // get end time 
  clock_t end = clock();

  // calc delta time in ms
  double deltaTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
  std::cout << "Time: " << deltaTime << " ms" << std::endl;
  return 0;
}
