#include "Code1.hpp"  // c++ main.cpp Code1.cpp -o Code1
using namespace std;

int main() {
  GetData menu;  // obj constructor, link from outside class to class
  char choice;

  do {
    cout << "\nMenu:\n";
    cout << "A. Output all values\n";
    cout << "B. Sum all values\n";
    cout << "C. Highest Value\n";
    cout << "D. Lowest Value\n";
    cout << "E. Median Values\n";
    cout << "F. Mean Value\n";
    cout << "G. Mode \n";
    cout << "H. Exit\n";
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
        menu.highestValue();
        break;
      case 'D':
        menu.lowestValue();
        break;
      case 'E':
        menu.medianValues();
        break;
      case 'F':
        menu.meanAverage();
        break;
      case 'G':
        menu.mode();
        break;
      case 'H':
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
        break;
    }
  } while (choice != 'H');

  return 0;
}