#include <iostream>
#include <cstdlib>    
#include <ctime>      
#include <chrono> //timing

//array of rand floats
void generateRandomArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 1000.0));
    }
}

// bubble Sort
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

//insertion sort
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

    //get start time
    auto start = std::chrono::high_resolution_clock::now();

    // algorythims
    bubbleSort(arr, SIZE);
    insertionSort(arr, SIZE);

    // get end time
    auto end = std::chrono::high_resolution_clock::now();

    // calc delta time in ms
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    //output time 
    std::cout << "Time to sort the array: " << duration.count() << " ms" << std::endl;

    return 0;
}
