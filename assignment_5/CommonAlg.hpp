#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

class CommonAlg {
private:
    int* array; //pointer to array
    int size;

public:
    CommonAlg();  // class constructor

    // read array from a file into the buffer
    bool readArrayFromFile(const std::string& filename);

    // methods
    void outputAllValues();
    int sumAllValues();
    void outputOddValues();
    void outputEvenValues();
    void middleValues();
    void firstValue();
    void lastValue();
    void highestValue();
    void lowestValue();
    void bubbleSort(bool output);
    void meanAverage();
    void binarySearch();
};