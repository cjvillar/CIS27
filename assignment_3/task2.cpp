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

  void firstValue(int array[]) { cout << "First value: " << array[0] << endl; }

  void lastValue(int array[]) { cout << "last value: " << array[1000] << endl; }

  void highestValue(int array[], int size) {
    int max_val = array[0];

    for (int i = 1; i < size; ++i) {
      if (array[i] > max_val) {
        max_val = array[i];
      }
      cout << max_val << endl;
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
    cout << "1. Linear Search\n";
    cout << "2. Middle Values\n";
    cout << "3. First Value\n";
    cout << "4. Last Value\n";
    cout << "5. Highest Value\n";
    cout << "6. Lowest Value\n";
    cout << "7. Bubble Sort\n";
    cout << "8. Mean Average\n";
    cout << "9. Exit\n";
    cin >> choice;
    switch (choice) {
      case 1:
        menu.linearSearch(menu.array, Menu::size);
        break;
      case 2:
        menu.middleValues(menu.array, Menu::size);
        break;
      case 3:
        menu.firstValue(menu.array);
        break;
      case 4:
        menu.lastValue(menu.array);
        break;
      case 5:
        menu.highestValue(menu.array, Menu::size);
        break;
      case 6:
        menu.lowestValue(menu.array, Menu::size);
        break;
      case 7:
        menu.bubbleSort(menu.array, Menu::size);
        break;
      case 8:
        menu.meanAverage(menu.array, Menu::size);
        break;
      case 9:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
  } while (choice != 9);

  return 0;
}
