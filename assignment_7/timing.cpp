#include <cstdlib>  
#include <ctime>    
#include <iostream>

void generateRandomArray(float arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] =
        static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 1000.0));
  }
}

void bubbleSort(float arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j + 1]
        float temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertionSort(float arr[], int size) {
  for (int i = 1; i < size; i++) {
    float key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
  //insertionSort(arr, SIZE);

  // get end time
  clock_t end = clock();

  // calc delta time in ms
  double deltaTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;

  // Output the time taken to sort the array
  std::cout << "Time: " << deltaTime << " ms"
            << std::endl;

  return 0;
}
