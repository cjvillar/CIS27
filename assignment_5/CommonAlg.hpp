#pragma once  // preprocessor directive

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <ctime>  // for srand
#include <string>

class CommonAlg {
 public:
  
  int *array ;
  int size ;

  CommonAlg();  // class constructor

  // read array from a file into the buffer
  bool readArrayFromFile(const std::string& filename, int*& array, int& size);

  void outputAllValues(const int arr[], int size);
  int sumAllValues(const int arr[], int size);
  void outputOddValues(const int arr[], int size);
  void outputEvenValues(const int arr[], int size);
  void middleValues(int array[], int size);
  void firstValue(int array[]);
  void lastValue(int array[]);
  void highestValue(int array[], int size);
  void lowestValue(int array[], int size);
  void bubbleSort(int array[], int size, bool output);
  void meanAverage(int array[], int size);
  void binarySearch(int array[], int size);
};
