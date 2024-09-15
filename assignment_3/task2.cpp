#include <cstdlib>
#include <ctime>  // for srand
#include <iostream>

using namespace std;

class Menu {
 public:
  // note: static const shared with all instances of this class
  static const int size = 1000;  // fixed size of 1000 for the array
  int array[size];

  Menu() {
    // init random number generator
    srand(static_cast<unsigned int>(time(0)));
    // fill array with random values
    for (int i = 0; i < size; ++i) {
      array[i] = rand() % 1000 + 1;
    }
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
    return sum;
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
    // only worry about even
    int middleValue;
    if (size % 2 == 0) {
      int middleIndex1 = size / 2 - 1;
      int middleIndex2 = size / 2;
      middleValue = (array[middleIndex1] + array[middleIndex2]) / 2;
    }

    std::cout << "Middle value: " << middleValue << std::endl;
  }

  void firstValue(int array[]) {
    cout << "First value: " << array[0] << "Index: 0" << endl;
  }

  void lastValue(int array[]) {
    cout << "last value: " << array[1000] << "Index: 1000" << endl;
  }

  void highestValue(int array[], int size) {
    int max_val = array[0];

    for (int i = 1; i < size; ++i) {
      if (array[i] > max_val) {
        max_val = array[i];
      }
      cout << "Highest Value: " << max_val << "Index: " << i << endl;
    }
  };

  void lowestValue(int array[], int size) {
    int min_val = array[0];

    for (int i = 1; i < size; ++i) {
      if (array[i] < min_val) {
        min_val = array[i];
      }
      cout << min_val << endl;
    }
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
    int sum;  // init sum
    for (int i = 1; i < size; ++i) {
      sum += array[i];  // add up all elements
    }
    int meanAvg = sum / size;
    std::cout << "Meand Average: " << meanAvg << endl;
  };
};

int main() {
  Menu menu;

  int choice;
  do {
    cout << "\nMenu:\n";
    cout << "1. Output all values\n";
    cout << "2. Sum all values\n";
    cout << "3. Output odd numbers\n";
    cout << "4. Output even numbers\n";
    cout << "5. Linear Search\n";
    cout << "6. Middle Values\n";
    cout << "7. First Value\n";
    cout << "8. Last Value\n";
    cout << "9. Highest Value\n";
    cout << "10. Lowest Value\n";
    cout << "11. Bubble Sort\n";
    cout << "12. Mean Average\n";
    cout << "13. Exit\n";
    cin >> choice;
    switch (choice) {
      case 1:
        menu.outputAllValues(menu.array, Menu::size);
        break;
      case 2:
        menu.sumAllValues(menu.array, Menu::size);
        break;
      case 3:
        menu.outputOddValues(menu.array, Menu::size);
        break;
      case 4:
        menu.outputEvenValues(menu.array, Menu::size);
        break;
      case 5:
        menu.linearSearch(menu.array, Menu::size);
        break;
      case 6:
        menu.middleValues(menu.array, Menu::size);
        break;
      case 7:
        menu.firstValue(menu.array);
        break;
      case 8:
        menu.lastValue(menu.array);
        break;
      case 9:
        menu.highestValue(menu.array, Menu::size);
        break;
      case 10:
        menu.lowestValue(menu.array, Menu::size);
        break;
      case 11:
        menu.bubbleSort(menu.array, Menu::size);
        break;
      case 12:
        menu.meanAverage(menu.array, Menu::size);
        break;
      case 13:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
  } while (choice != 13);

  return 0;
}
