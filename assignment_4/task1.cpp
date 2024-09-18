#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;
const int size = 1000;  // fixed size of 1000 for the array

void randNum(int arr[]) {
  srand(static_cast<unsigned int>(time(0)));  // seed  with srand
  for (int i = 0; i < size; ++i) {            // fill with rand values
    arr[i] = rand() % 1000 + 1;
  }
}

void saveRandNum(const int arr[]) {
  ofstream outfile("array.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open file for writing.\n";
    return;  // exit if file error
  }

  // write file
  for (int i = 0; i < size; ++i) {
    outfile << arr[i] << " \n";  // save each int on new line
    cout << arr[i] << " ";       // out to console
  }

  // close file
  outfile.close();
}

int main() {
  int nums[size];
  randNum(nums);
  saveRandNum(nums);

  return 0;
}
