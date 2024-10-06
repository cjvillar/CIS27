#include "CommonAlg.hpp"  // c++ main.cpp CommonAlg.cpp -o CommonAlg

using namespace std;

int main() {
  CommonAlg menu;  // obj constructor, link from outside class to class
  char choice;

  do {
    cout << "\nMenu:\n";
    cout << "A. Output all values\n";
    cout << "B. Sum all values\n";
    cout << "C. Output odd numbers\n";
    cout << "D. Output even numbers\n";
    cout << "E. Binary Search\n";
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
        menu.outputAllValues();
        break;
      case 'B':
        cout << "Sum: " << menu.sumAllValues() << endl;
        break;
      case 'C':
        menu.outputOddValues();
        break;
      case 'D':
        menu.outputEvenValues();
        break;
      case 'E':
        menu.binarySearch();
        break;
      case 'F':
        menu.middleValues();
        break;
      case 'G':
        menu.firstValue();
        break;
      case 'H':
        menu.lastValue();
        break;
      case 'I':
        menu.highestValue();
        break;
      case 'J':
        menu.lowestValue();
        break;
      case 'K':
        menu.bubbleSort(true);
        break;
      case 'L':
        menu.meanAverage();
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