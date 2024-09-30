#include "CommonAlg.hpp"

using namespace std;

//make array a class variable so i dont needd to pass to each method

CommonAlg::CommonAlg() {
  if (!readArrayFromFile("array.txt")) {
    std::cerr << "Error reading array file." << std::endl;
  }}

bool CommonAlg::readArrayFromFile(const std::string &filename) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }

  int value;
  char delim; // to store deliminator 

  array = new int[1];  // init array with new
  if (array == nullptr) {
    std::cerr << "Memory Read Error." << std::endl;
    return false;
  }
  size = 0;

  while (infile >> value) {
    int* temp = new int[size + 1];  // temp array for reallocation
    if (temp == nullptr) {
      std::cerr << "Memory write error." << std::endl;
      delete[] array;
      return false;
    }
    std::copy(array, array + size, temp);  //copy data to temp arr
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

void CommonAlg::outputAllValues() {
  cout << "All values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int CommonAlg::sumAllValues() {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += array[i];
  }
  return sum;
}

void CommonAlg::outputOddValues() {
  cout << "Odd values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (array[i] % 2 != 0) {
      cout << array[i] << " ";
    }
  }
  cout << endl;
}

void CommonAlg::outputEvenValues() {
  cout << "Even values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (array[i] % 2 == 0) {
      cout << array[i] << " ";
    }
  }
  cout << endl;
}

void CommonAlg::middleValues() {
  int middleValue;
  if (size % 2 == 0) {
    int middleIndex1 = size / 2 - 1;
    int middleIndex2 = size / 2;
    middleValue = (array[middleIndex1] + array[middleIndex2]) / 2;
  }
  std::cout << "Middle value: " << middleValue << std::endl;
}

void CommonAlg::firstValue() {
  cout << "First value: " << array[0] << " Index: 0" << endl;
}

void CommonAlg::lastValue() {
  cout << "Last value: " << array[size - 1] << " Index: " << size - 1 << endl;
}

void CommonAlg::highestValue() {
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

void CommonAlg::lowestValue() {
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
//bool for output 
void CommonAlg::bubbleSort(bool output=true) {
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

void CommonAlg::meanAverage() {
  int sum = sumAllValues();
  int meanAvg = sum / size;
  std::cout << "Mean Average: " << meanAvg << endl;
}

void CommonAlg::binarySearch() {
  if (size <= 0) {
    cout << "Array is empty or size is invalid." << endl;
    return;
  }

  // sort array with bubble sort
  bubbleSort(false);

  int target;
  cout << "Enter target: ";

  // target validation ( stops infinite loop if not int)
  while (!(cin >> target)) {
    cout << "Invalid input. Please enter an integer: ";
    cin.clear();
    cin.ignore(10, '\n');
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