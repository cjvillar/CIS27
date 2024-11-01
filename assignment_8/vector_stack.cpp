#include <iostream>
#include <stack>
#include <string>

using namespace std;

class STACK {
 private:
  stack<char> stackVector;

 public:
  bool push(char);
  char pop();
  bool isEmpty();
  char peek();
};

bool STACK::push(char n) {
  stackVector.push(n);
  return true;
}

char STACK::pop() {
  if (isEmpty()) {
    cout << "Stack is empty, cant pop." << endl;
    return '\0';  // return null char for empty stack
  }
  char topElement = stackVector.top();
  stackVector.pop();
  return topElement;
}

bool STACK::isEmpty() { return stackVector.empty(); }

char STACK::peek() {
  if (!isEmpty()) {
    return stackVector.top();
  }
  return '\0';  // null char if empty
}

int main() {
  STACK stack;
  string input;

  cout << "Please input a string: ";
  cin >> input;

  // push chars  on stack
  for (char c : input) {
    stack.push(c);
  }

  cout << "Reversed string: ";

  // pop
  while (!stack.isEmpty()) {
    cout << stack.pop();
  }

  cout << endl;

  return 0;
}
