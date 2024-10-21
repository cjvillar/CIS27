#include "Code1.hpp"

using namespace std;

GetData::GetData() {
  if (!readArrayFromFile("floatvalues-1.txt.txt")) {
    std::cerr << "Error reading array file." << std::endl;
  }
}

bool GetData::readArrayFromFile(const std::string& filename) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }

  float value;
  size = 0;
  array = nullptr;

  while (infile >> value) {
    float* temp =
        new float[size + 1];  // create a new array with increased size

    if (temp == nullptr) {
      std::cerr << "Memory allocation error." << std::endl;
      delete[] array;
      return false;
    }

    // copy old values to the new array
    for (int i = 0; i < size; ++i) {
      temp[i] = array[i];
    }

    temp[size] = value;
    delete[] array;
    array = temp;
    size++;
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

void GetData::outputAllValues() {
  std::cout << std::fixed << std::setprecision(2);  // for float precision
  std::cout << "All values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << endl;
}

float GetData::sumAllValues() {
  std::cout << std::fixed << std::setprecision(2);
  float sum = 0.00;
  for (int i = 0; i < size; ++i) {
    sum += array[i];
  }
  return sum;
}

void GetData::bubbleSort() {  // for getting median
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        float temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void GetData::medianValues() {
  float middleValue;
  bubbleSort();
  if (size % 2 == 0) {
    int middleIndex1 = size / 2 - 1;
    int middleIndex2 = size / 2;
    middleValue = (array[middleIndex1] + array[middleIndex2]) / 2.0f;
  } else {
    middleValue = array[size / 2];
  }
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Middle value: " << middleValue << std::endl;
}

void GetData::meanAverage() {
  float sum = sumAllValues();
  float meanAvg = sum / size;
  std::cout << "Mean Average: " << meanAvg << endl;
}

void GetData::mode() { 
  int mode_count = 0;
  float mode_value = 0.00;
  for (int i = 1; i < size; ++i) {
    int count = 0;
    for (int j = 1; j < size; ++j) {
      if (array[i] == array[j]) {
        count ++;
      }
    }
    if(count > mode_count ){
      mode_count = count;
      mode_value = array[i];
    }
  }
  cout << "mode value: " << mode_value << endl;
}

void GetData::highestValue() {
  float max_val = array[0];
  int max_index = 0;

  for (int i = 1; i < size; ++i) {
    if (array[i] > max_val) {
      max_val = array[i];
      max_index = i;
    }
  }
  std::cout << std::fixed << std::setprecision(2);
  cout << "Highest Value: " << max_val << " Index: " << max_index << endl;
}

void GetData::lowestValue() {
  float min_val = array[0];
  int min_index = 0;
  for (int i = 1; i < size; ++i) {
    if (array[i] < min_val) {
      min_val = array[i];
      min_index = i;
    }
  }
  std::cout << std::fixed << std::setprecision(2);
  cout << "Lowest Value: " << min_val << " Index: " << min_index << endl;
}
