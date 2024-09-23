#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

const int size = 1000;  // fixed size 1000 
const int bufferSize = 1000;  // buffer size

void generateRandomNumbers(int arr[]) {
    std::srand(static_cast<unsigned int>(std::time(0)));  // seed with srand
    for (int i = 0; i < size; ++i) {            // fill with random values
        arr[i] = std::rand() % 1000 + 1;
    }
}

void saveRandomNumbers(const int arr[]) {
    char buffer[bufferSize];  // buffer
    std::ofstream outfile("array.txt", std::ios::binary);
    std::cin.getline(buffer, bufferSize)
    outfile.rdbuf()->pubsetbuf(buffer, bufferSize);  //  buffer

    if (!outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // writeto the file using the buffer
    outfile.write(reinterpret_cast<const char*>(arr), size * sizeof(int));
    
    
}

//create a readfile function

void readFile(){
    // ouput to std out
}

int main() {
    int nums[size];
    generateRandomNumbers(nums);  // rand number generator 

    saveRandomNumbers(nums);  // Save to file

    return 0;
}
