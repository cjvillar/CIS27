#include <iostream>
#include <string>

#define SIZE 5

using namespace std;

class STACK {
 private:
  char array[SIZE];
  int top;

 public:
  STACK();  // default constructor
  bool push(char);
  char pop();
  bool isEmpty();
  bool isFull();
  char peek();
};

STACK::STACK() { top = -1; }

bool STACK::push(char n) {
  if (isFull()) {
    cout << "Stack is full, cant push." << endl;
    return false;
  }
  array[++top] = n;
  return true;
}

char STACK::pop() {
  if (isEmpty()) {
    cout << "Stack is empty, cant pop." << endl;
    return '\0';  // return null char for empty stack
  }
  return array[top--];
}

bool STACK::isEmpty() { return top == -1; }
bool STACK::isFull() { return top == SIZE - 1; }

char STACK::peek() {  // return top char without removeing it
  if (!isEmpty()) {
    return array[top];
  }
  return '\0';  // null char if empty
}

int main() {
  STACK stack;
  string input;

  cout << "Please input a string: ";
  cin >> input;

  // push all chars of string on stack
  for (char c : input) {
    if (!stack.push(c)) {
      break;  // stack full
    }
  }

  cout << "Reversed string: ";

  // pop all chars in reverse
  while (!stack.isEmpty()) {
    cout << stack.pop();
  }
  cout << endl;
  return 0;
}
