#include "CommonAlg.hpp"

using namespace std;

CommonAlg::CommonAlg() {
  if (!readArrayFromFile("array.txt", array, size)) {
    std::cerr << "Error reading array file." << std::endl;
  }}

bool CommonAlg::readArrayFromFile(const std::string &filename, int *&array, int &size) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }

  int value;
  char delim;

  array = new int[1];  // init array with new
  if (array == nullptr) {
    std::cerr << "Error allocating memory." << std::endl;
    return false;
  }
  size = 0;

  while (infile >> value) {
    int* temp = new int[size + 1];  // temp array for reallocation
    if (temp == nullptr) {
      std::cerr << "Error reallocating memory." << std::endl;
      delete[] array;
      return false;
    }
    std::copy(array, array + size, temp);  // copy data to temp
    temp[size] = value;
    delete[] array;  // free original array
    array = temp;
    size++;
    infile >> delim;
  }

  if (infile.fail() && !infile.eof()) {
    std::cerr << "Error reading data from file." << std::endl;
    delete[] array;
    array = nullptr;
    return false;
  }

  infile.close();
  return true;
}

void CommonAlg::outputAllValues(const int arr[], int size) {
  cout << "All values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int CommonAlg::sumAllValues(const int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  return sum;
}

void CommonAlg::outputOddValues(const int arr[], int size) {
  cout << "Odd values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (arr[i] % 2 != 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

void CommonAlg::outputEvenValues(const int arr[], int size) {
  cout << "Even values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (arr[i] % 2 == 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

void CommonAlg::middleValues(int array[], int size) {
  int middleValue;
  if (size % 2 == 0) {
    int middleIndex1 = size / 2 - 1;
    int middleIndex2 = size / 2;
    middleValue = (array[middleIndex1] + array[middleIndex2]) / 2;
  }
  std::cout << "Middle value: " << middleValue << std::endl;
}

void CommonAlg::firstValue(int array[]) {
  cout << "First value: " << array[0] << " Index: 0" << endl;
}

void CommonAlg::lastValue(int array[]) {
  cout << "Last value: " << array[size - 1] << " Index: " << size - 1 << endl;
}

void CommonAlg::highestValue(int array[], int size) {
  int max_val = array[0];
  int max_index = 0;

  for (int i = 1; i < size; ++i) {
    if (array[i] > max_val) {
      max_val = array[i];
      max_index = i;
    }
  }
  cout << "Highest Value: " << max_val << " Index: " << max_index << endl;
}

void CommonAlg::lowestValue(int array[], int size) {
  int min_val = array[0];
  int min_index = 0;

  for (int i = 1; i < size; ++i) {
    if (array[i] < min_val) {
      min_val = array[i];
      min_index = i;
    }
  }
  cout << "Lowest Value: " << min_val << " Index: " << min_index << endl;
}

void CommonAlg::bubbleSort(int array[], int size, bool output) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  if(output){ // maybe hacky but works to mute output for binarySearch
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  
  cout << endl;
  }
}

void CommonAlg::meanAverage(int array[], int size) {
  int sum = sumAllValues(array, size);
  int meanAvg = sum / size;
  std::cout << "Mean Average: " << meanAvg << endl;
}

void CommonAlg::binarySearch(int array[], int size) {
  if (size <= 0) {
    cout << "Array is empty or size is invalid." << endl;
    return;
  }

  // sort array with bubble sort
  bubbleSort(array, size, false);

  int target;
  cout << "Enter target: ";

  // target validation ( stops infinite loop if not int)
  while (!(cin >> target)) {
    cout << "Invalid input. Please enter an integer: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  int left = 0;
  int right = size - 1;

  // binary search
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (array[mid] == target) {
      cout << "Target: " << target << ", Index: " << mid << endl;
      return;
    } 
    // target is greater, move left pointer
    else if (array[mid] < target) {
      left = mid + 1;
    } 
    //target is smaller, move right pointer
    else {
      right = mid - 1;
    }
  }
  // target not found
  cout << "Target: " << target << " not found" << endl;
}