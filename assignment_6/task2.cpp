#include <iostream>

class My_String {
 private:  // private access specifier
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

  int length() {
    int len = 0;
    for (int i = 0; inputBuffer[i] != '\0'; ++i) {
      len++;
    }

    std::cout << "Length of the string: " << len << std::endl;
    return 0;
  };

  int Isalpha() {
    int index_loc[size];  // init array to store index
    int count = 0;

    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] < 65 || inputBuffer[i] > 90) &&
          (inputBuffer[i] < 97 || inputBuffer[i] > 122)) {
        index_loc[count] = i;
        count++;
      }
    }
    //loop through non alph chars if any
    if (count > 0) {
      for (int i = 0; i < count; ++i) {
        std::cout << "Non Alpha char detected at index: " << index_loc[i]
                  << std::endl;
      }
    } else {
      std::cout << "No Non-Alpha chars detected" << std::endl;
    }
    return 0;
  };

  void Toupper() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 97 && inputBuffer[i] <= 122)) {
        inputBuffer[i] -= 32;  // subtract 32 to make ascii uppercase
      }
    }
    userOutput();
  };

  void Tolower() {
    for (int i = 0; i < size; ++i) {
      // check ascii
      if ((inputBuffer[i] >= 65 && inputBuffer[i] <= 90)) {
        inputBuffer[i] += 32;  // add 32 to make ascii uppercase
      }
    }
    userOutput();
  };

  void Pushback() {
    std::cout << "Enter a string to append: "; 
    char appendChar[100]; // temp buffer to hold new chars
    std::cin.ignore(); // clear input buff from menu
    std::cin.getline(appendChar, 100); // get char from user

    int appendLen = 0;  // calc new chars
    while (appendChar[appendLen] != '\0') {
      appendLen++;
    }

    // new buffer size
    char* newBuffer = new char[size + appendLen + 1];  // +1 for null terminator

    // copy init string into buff
    for (int i = 0; i < size; ++i) {
      newBuffer[i] = inputBuffer[i];
    }

    // append
    for (int i = 0; i < appendLen; ++i) {
      newBuffer[size + i] = appendChar[i];
    }

    // null terminator
    newBuffer[size + appendLen] = '\0';

    // delete old buff and update the input
    delete[] inputBuffer;
    inputBuffer = newBuffer;
    size += appendLen;

    // Output new string
    userOutput();
  }
};

int main() {
  My_String my_string;

  // get user input string
  my_string.userInput();

  char choice;
  do {
    std::cout << "\nMenu:\n";
    std::cout << "A. Output length of string\n";
    std::cout << "B. Output index of non-alph char\n";
    std::cout << "C. Outputl Lower to Upper case\n";
    std::cout << "D. Outputl Upper to Lower case\n";
    std::cout << "E. Append\n";
    std::cout << "F. Exit\n";
    std::cin >> choice;
    choice = toupper(choice);  // only use uppercase

    switch (choice) {
      case 'A':
        my_string.length();
        break;
      case 'B':
        my_string.Isalpha();
        break;
      case 'C':
        my_string.Toupper();
        break;
      case 'D':
        my_string.Tolower();
        break;
      case 'E':
        my_string.Pushback();
        break;
      case 'F':
        std::cout << "Exiting program." << std::endl;
        break;
      default:
        std::cout << "Invalid choice, please try again." << std::endl;
        break;
    }
  } while (choice != 'F');

  return 0;
}