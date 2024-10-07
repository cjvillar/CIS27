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

  // clear buffer so new password can be created
  void resetInputBuffer() {
    delete[] inputBuffer;
    inputBuffer = nullptr;
    size = 0;
  }

  int CheckLength() {
    int len = 0;
    for (int i = 0; inputBuffer[i] != '\0'; ++i) {
      len++;
    }
    return len;
  };

  bool CheckSpecial() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] < 65 || inputBuffer[i] > 90) &&
          (inputBuffer[i] < 97 || inputBuffer[i] > 122) &&
          (inputBuffer[i] < 48 || inputBuffer[i] > 57)) {
        return true;
      }
    }
    return false;
  };

  bool CheckNum() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 48 && inputBuffer[i] <= 57)) {
        return true;
      }
    }
    return false;
  };

  bool CheckUpper() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 65 && inputBuffer[i] <= 90)) {
        return true;
      }
    }
    return false;
  };

  bool CheckLower() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 97 && inputBuffer[i] <= 122)) {
        return true;
      }
    }
    return false;
  };
  // user output method
  void OutPassword() const { std::cout << inputBuffer << std::endl; }
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

    } else if (!password_check.CheckSpecial()) {
      std::cout << "Password Needs Special Character." << std::endl;
      password_check.resetInputBuffer();
    } else if (!password_check.CheckUpper()) {
      std::cout << "Password Needs Uppercase Character." << std::endl;
      password_check.resetInputBuffer();
    } else if (!password_check.CheckLower()) {
      std::cout << "Password Needs Lowercase Character." << std::endl;
      password_check.resetInputBuffer();
    } else if (!password_check.CheckNum()) {
      std::cout << "Password Needs A Number." << std::endl;
      password_check.resetInputBuffer();
    } else {
      std::cout << "Password OK!" << std::endl;
      // show password for debugging
      password_check.OutPassword();
      goodPassword = true;
    }
  }
  return 0;
}