#include <iostream>

using namespace std;

void binarySearch(int array[], int size) {
  if (size <= 0) {
    cout << "Array is empty or size is invalid." << endl;
    return;
  }

  int target;
  cout << "Enter target: ";

  // target validation ( stops infinite loop if not int)
  while (!(cin >> target)) {
    cout << "Invalid input. Please enter an integer: ";
    cin.clear();
    cin.ignore(10, '\n');
  }

  int left = 0;
  int right = size - 1;

  // binary search
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (array[mid] == target) {
      cout << "Target: " << target << ", Index: " << mid << endl;
      return;
    }
    // target is greater, move left pointer
    else if (array[mid] < target) {
      left = mid + 1;
    }
    // target is smaller, move right pointer
    else {
      right = mid - 1;
    }
  }
  // target not found
  cout << "Target: " << target << " not found" << endl;
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = 10;
  binarySearch(array, size);
  return 0;
}