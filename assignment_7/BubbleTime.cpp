#include <cstdlib>  
#include <ctime>    
#include <iostream>

void generateRandomArray(float arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] =
        static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 1000.0)); }
}

void bubbleSort(float arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        float temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp; } }
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
  bubbleSort(arr, SIZE);
 
  // get end time
  clock_t end = clock();

  // calc delta time in ms
  double deltaTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
  std::cout << "Time: " << deltaTime << " ms"<< std::endl;
  return 0;
}
