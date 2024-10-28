#include <iostream>
#include <stack>
#include <string>

using namespace std;

class STACK {
 private:
  stack<char> stackContainer;

 public:
  bool push(char);  
  char pop(); 
  bool isEmpty();
  char peek();  
};

bool STACK::push(char n) {
  stackContainer.push(n);
  return true;
}

char STACK::pop() {
  if (isEmpty()) {
    cout << "Stack is empty, can't pop." << endl;
    return '\0';  // return null char for empty stack
  }
  char topElement = stackContainer.top();
  stackContainer.pop();
  return topElement;
}

bool STACK::isEmpty() { return stackContainer.empty(); }

char STACK::peek() {
  if (!isEmpty()) {
    return stackContainer.top();
  }
  return '\0';  // null char if empty
}

int main() {
  STACK stack;
  string input;

  cout << "Please input a string: ";
  cin >> input;

  // Push all chars of the string onto the stack
  for (char c : input) {
    stack.push(c);
  }

  cout << "Reversed string: ";
  
  // Pop all chars in reverse
  while (!stack.isEmpty()) {
    cout << stack.pop();
  }

  cout << endl;

  return 0;
}
