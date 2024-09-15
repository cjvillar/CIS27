#include <cstdlib>
#include <ctime>  // for random
#include <iostream>

using namespace std;

void outputAllNumbers(const int arr[], int size) {
  cout << "All values in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void outputOddNumbers(const int arr[], int size) {
  cout << "Odd numbers in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (arr[i] % 2 != 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

void outputEvenNumbers(const int arr[], int size) {
  cout << "Even numbers in the array:" << endl;
  for (int i = 0; i < size; ++i) {
    if (arr[i] % 2 == 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

// Add sum all values function
int sumAllValues(const int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  return sum;
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


int main() {
  srand(static_cast<unsigned int>(time(0)));//  random with srand
  const int size = 1000;  // fixed size of 1000 for the array
  int array[size];

  for (int i = 0; i < size; ++i) { // fill array with random values
    array[i] = rand() % 1000 + 1;
  }
  int choice;
  do {
    cout << "\nMenu:\n";
    cout << "1. Output all values\n";
    cout << "2. Output odd numbers\n";
    cout << "3. Output even numbers\n";
    cout << "4. Sum all values\n";
    cout << "5. Search Value\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        outputAllNumbers(array, size);
        break;
      case 2:
        outputOddNumbers(array, size);
        break;
      case 3:
        outputEvenNumbers(array, size);
        break;
      case 4:
        cout << "Sum of all values: " << sumAllValues(array, size) << endl;
        break;
      case 5:
        linearSearch(array, size);
        break;
      case 6:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
  } while (choice != 6);

  return 0;
}
