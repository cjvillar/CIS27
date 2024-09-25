#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int size = 1000;  // array size

// write array data into a file
void writeFile(const string& filename) {
  int buffer[size];  // buffer (temp array)

  // fill buffer with random values
  for (int i = 0; i < size; ++i) {
    buffer[i] = rand() % 1000 + 1;
  }

  ofstream outfile(filename);
  if (!outfile.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return;
  }

  // write buffer to file
  for (int i = 0; i < size; ++i) {
    outfile << buffer[i] << ", ";  // comma delimited
  }

  outfile.close();  // close the file
}

// read array data from file and output to stdout
void readFile(const string& filename) {
  int buffer[size];  // init buffer (again)

  ifstream infile(filename); //ifstream handles conversion str to int
  if (!infile.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return;
  }

  // read data from file into buffer
  for (int i = 0; i < size; ++i) {
    infile >> buffer[i];
  }

  infile.close();  // close the file

  // output buffer data
  for (int i = 0; i < size; ++i) {
    cout << buffer[i] << " ";
  }
  cout << endl;
}

int main() {
  srand(static_cast<unsigned int>(time(0))); //rand num seed
  writeFile("array.txt"); //write to file
  readFile("array.txt");

  return 0;
}
