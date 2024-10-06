#include <iostream>

int main() {
  // Dynamically allocate an array of 5 integers using new
  int* dynamicArray = new int[5];

  // Assign values to the array
  for (int i = 0; i < 5; i++) {
    dynamicArray[i] = i * 10;
  }

  // Print the array
  std::cout << "Dynamic Array: ";
  for (int i = 0; i < 5; i++) {
    std::cout << dynamicArray[i] << " ";
  }
  std::cout << std::endl;

  // Use move semantics to transfer ownership
  int* movedArray = dynamicArray;
  dynamicArray = nullptr; // Set original pointer to nullptr

  // Print the moved array
  std::cout << "Moved Array: ";
  for (int i = 0; i < 5; i++) {
    std::cout << movedArray[i] << " ";
  }
  std::cout << std::endl;

  // Dynamically deallocate the memory using delete[]
  delete[] movedArray;

  // Attempting to access deleted memory will result in undefined behavior
  // std::cout << movedArray[0] << std::endl; // Don't do this!

  return 0;
}