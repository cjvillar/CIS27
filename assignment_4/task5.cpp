#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <ctime>  // for srand
#include <iostream>

using namespace std;

class Common_Alg {
 public:
  static const int size = 1000;
  int array[size];  // array size of 1000

  Common_Alg() {  // class constructor ( not required for code to work)
    // read array from file
    if (!readArrayFromFile("array.txt")) {
      std::cerr << "Error reading array from file." << std::endl;
    }
  }

   // read array from a file into the buffer
  bool readArrayFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
      std::cerr << "Error opening file: " << filename << std::endl;
      return false;
    }

    // Read data into array (class variable)
    for (int i = 0; i < size; ++i) {
      char delim; //remove delim
      infile >> array[i];
      infile >> delim; // put delim here 
      if (infile.fail()) {
        std::cerr << "Error reading data from file." << std::endl;
        return false;
      }
    }

    infile.close();
    return true;
  }

  

  void outputAllValues(const int arr[], int size) {
    cout << "All values in the array:" << endl;
    for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int sumAllValues(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
      sum += arr[i];
    }
  }

  void outputOddValues(const int arr[], int size) {
    cout << "Odd values in the array:" << endl;
    for (int i = 0; i < size; ++i) {
      if (arr[i] % 2 != 0) {
        cout << arr[i] << " ";
      }
    }
    cout << endl;
  }

  void outputEvenValues(const int arr[], int size) {
    cout << "Even values in the array:" << endl;
    for (int i = 0; i < size; ++i) {
      if (arr[i] % 2 == 0) {
        cout << arr[i] << " ";
      }
    }
    cout << endl;
  }

  void linearSearch(int array[], int size) {
    int target;
    cout << "Enter target: ";
    cin >> target;
    for (int i = 0; i < size; i++) {
      if (array[i] == target) {
        cout << "Target: " << target << ", index: " << i << endl;
        return;
      }
    }
    cout << "Target not found" << endl;
  }

  void middleValues(int array[], int size) {
    // only worry about even: 1000 is even
    int middleValue;
    if (size % 2 == 0) {
      int middleIndex1 = size / 2 - 1;
      int middleIndex2 = size / 2;
      middleValue = (array[middleIndex1] + array[middleIndex2]) / 2;
    }

    std::cout << "Middle value: " << middleValue << std::endl;
  }

  void firstValue(int array[]) {
    cout << "First value: " << array[0] << " Index: 0" << endl;
  }

  void lastValue(int array[]) {
    cout << "last value: " << sizeof(array) - 1 << " Index: " << size - 1
         << endl;
  }

  void highestValue(int array[], int size) {
    int max_val = array[0];
    int max_index = 0;

    for (int i = 1; i < size; ++i) {
      if (array[i] > max_val) {
        max_val = array[i];
        max_index = i;
      }
    }
    cout << "Highest Value: " << array[max_val] << " Index: " << max_index
         << endl;
  };

  void lowestValue(int array[], int size) {
    int min_val = array[0];
    for (int i = 1; i < size; ++i) {
      if (array[i] < min_val) {
        min_val = array[i];
      }
    }
    cout << "Lowest Value: " << min_val << " Index: " << array[min_val] << endl;
  };

  void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (array[j] > array[j + 1]) {
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
      }
    }
    for (int i = 0; i < size; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  };

  void meanAverage(int array[], int size) {
    int sum = sumAllValues(array, size);
    int meanAvg = sum / size;
    std::cout << "Meand Average: " << meanAvg << endl;
  };
};

int main() {
  Common_Alg menu;  // obj constructor, link from outside class to class
  char choice;  // use char for memory

  do {
    cout << "\nMenu:\n";
    cout << "A. Output all values\n";
    cout << "B. Sum all values\n";
    cout << "C. Output odd numbers\n";
    cout << "D. Output even numbers\n";
    cout << "E. Linear Search\n";
    cout << "F. Middle Values\n";
    cout << "G. First Value\n";
    cout << "H. Last Value\n";
    cout << "I. Highest Value\n";
    cout << "J. Lowest Value\n";
    cout << "K. Bubble Sort\n";
    cout << "L. Mean Average\n";
    cout << "M. Exit\n";
    cin >> choice;
    choice = toupper(choice);  // only use uppercase

    switch (choice) {
      case 'A':
        menu.outputAllValues(menu.array, Common_Alg::size);
        break;
      case 'B':
        cout << "Sum: " << menu.sumAllValues(menu.array, Common_Alg::size)
             << endl;
        break;
      case 'C':
        menu.outputOddValues(menu.array, Common_Alg::size);
        break;
      case 'D':
        menu.outputEvenValues(menu.array, Common_Alg::size);
        break;
      case 'E':
        menu.linearSearch(menu.array, Common_Alg::size);
        break;
      case 'F':
        menu.middleValues(menu.array, Common_Alg::size);
        break;
      case 'G':
        menu.firstValue(menu.array);
        break;
      case 'H':
        menu.lastValue(menu.array);
        break;
      case 'I':
        menu.highestValue(menu.array, Common_Alg::size);
        break;
      case 'J':
        menu.lowestValue(menu.array, Common_Alg::size);
        break;
      case 'K':
        menu.bubbleSort(menu.array, Common_Alg::size);
        break;
      case 'L':
        menu.meanAverage(menu.array, Common_Alg::size);
        break;
      case 'M':
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
  } while (choice != 'M');

  return 0;
}