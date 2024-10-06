#include <iostream>

class PasswordCheck {
 private:  // private access specifier
  char* inputBuffer;
  int size;

 public:  // public access specifier
  // constructor
  PasswordCheck() : inputBuffer(nullptr), size(0) {}

  // destructor
  ~PasswordCheck() { delete[] inputBuffer; }

  // user input method
  void userInput() {
    std::cout << "Enter A Password: ";
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

  int CheckLength() {
    int len = 0;
    for (int i = 0; inputBuffer[i] != '\0'; ++i) {
      len++;
    }
    return len;
  };

  bool CheckAlpha() {
    int count = 0;

    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] < 65 || inputBuffer[i] > 90) &&
          (inputBuffer[i] < 97 || inputBuffer[i] > 122)) {
        count++;
      }
    }
    // loop through non alph chars if any
    if (count == 0) {
      std::cout << "Password Needs a Special Character" << std::endl;
      return false;
    } else {
      return true;
    }
  };

  bool CheckUpper() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 97 && inputBuffer[i] <= 122)) {
        count++;
      }
    }
    if (count == 0) {
      return false;
    } else {
      return true;
    }
  };

  bool CheckLower() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 65 && inputBuffer[i] <= 90)) {
        count++;
      }
    }
    if (count == 0) {
      return false;
    } else {
      return true;
    }
  };
};

int main() {
  PasswordCheck password_check;
  bool goodPassword;
  // keep checking until password ok
  while (!goodPassword) {
    // get user password
    password_check.userInput();

    // check password length
    int Passlen = password_check.CheckLength();
    if (Passlen < 8) {
      std::cout << "Password Too Short: " << Passlen << std::endl;

    } else if (!password_check.CheckAlpha()) {
      std::cout << "Password Needs Uppercase Character." << std::endl;

    } else if (!password_check.CheckLower()) {
      std::cout << "Password Needs Lowercase Character." << std::endl;

    } else {
      std::cout << "Password OK!" << std::endl;
      goodPassword = true;
    }
  }
  return 0;
}