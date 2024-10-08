#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> //for float precision

class GetData {
private:
    float* array; //pointer to array
    int size;

public:
    GetData();  // class constructor

    // read array from a file into the buffer
    bool readArrayFromFile(const std::string& filename);

    // methods
    void outputAllValues();
    float sumAllValues();
    void bubbleSort(); // just to sort for median
    void medianValues();
    void meanAverage();
    void mode();
    void highestValue();
    void lowestValue();
    
};