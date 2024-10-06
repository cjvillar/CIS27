#include <iostream>

class My_String {
 private:  // private access specifier
  // attributes
  char* inputBuffer;
  int size;

 public:  // public access specifier
  // constructor
  My_String() : inputBuffer(nullptr), size(0) {}

  // destructor
  ~My_String() { delete[] inputBuffer; }

  // user input method
  void userInput() {
    std::cout << "Enter a string: ";
    char c;
    while (std::cin.get(c) && c != '\n') {
      char* temp = new char[size + 2];  // +2 for new character and null pointer
      for (int i = 0; i < size; ++i) {
        temp[i] = inputBuffer[i];
      }
      temp[size] = c;
      temp[size + 1] = '\0';

      delete[] inputBuffer;
      inputBuffer = temp;
      size++;
    }
  }
  // user output method
  void userOutput() const { std::cout << inputBuffer << std::endl; }
};

int main() {
  My_String my_string;
  my_string.userInput();
  my_string.userOutput();
  return 0;
}