#include <iostream>
#include <string>

#define SIZE 10

using namespace std;

class STACK {
 private:
  char array[SIZE];
  int top;

 public:
  STACK();  // default constructor

  //methods
  bool push(char);
  char pop();
  bool isEmpty();
  bool isFull();
  char peek();
};

STACK::STACK() { top = -1; } // constructor inits tack with top = -1 (empty state)

bool STACK::push(char n) {
  if (isFull()) { //check full
    cout << "stack full, cant push." << endl;
    return false;
  }
  array[++top] = n; //increment top and add char to stck
  return true;
}

char STACK::pop() {
  if (isEmpty()) {
    cout << "stack empty, cant pop." << endl;
    return '\0';  // return null char for empty stack
  }
  return array[top--]; //return top char (pop)
}

bool STACK::isEmpty() { return top == -1; } //check empty 

bool STACK::isFull() { return top == SIZE - 1; } //check if full

char STACK::peek() {  // return top char without removeing it
  if (!isEmpty()) {
    return array[top]; //if not empty return top char
  }
  return '\0';  // null char if empty
}

int main() {
  STACK stack; //create stack obj
  string input; //var to hold usr input

  cout << "input a string: ";
  cin >> input;

  // push all chars of string on stack
  for (char c : input) {
    if (!stack.push(c)) { //if push stack full
      break;  // stack full
    }
  }

  cout << "reversed string: ";

  // pop all chars in reverse
  while (!stack.isEmpty()) {
    cout << stack.pop();
  }
  cout << endl;
  return 0;
}
