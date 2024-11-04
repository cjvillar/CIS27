#include <iostream>
#include <queue>
#include <string>

using namespace std;

class QUEUE {
 private:
  queue<char> queue;

 public:
  QUEUE();  // constructor
  //methods without isfull because I used std::queue 
  bool enqueue(char);
  char dequeue();
  bool isEmpty();
  char peek();
};

QUEUE::QUEUE() {}

bool QUEUE::enqueue(char c) {
  queue.push(c);  // push to queue
  return true;          // return true
}

char QUEUE::dequeue() {
  if (isEmpty()) {
    cout << "queue empty, cant dequeue." << endl;
    return '\0';  // null char if empty
  }
  char value = queue.front();  // get front char
  queue.pop();                 // remove first char
  return value;                      // return the dequeued char
}

bool QUEUE::isEmpty() { return queue.empty(); }


char QUEUE::peek() {  // return first char without removing it
  if (!isEmpty()) {
    return queue.front();
  }
  return '\0';  // Null char if empty
}

int main() {
  QUEUE queue;
  string input;

  cout << "Input string: ";
  cin >> input;

  for (char c : input) {
    if (!queue.enqueue(c)) {
      break;  // queue full
    }
  }

  cout << "Doubled output: ";

  while (!queue.isEmpty()) {
    char c = queue.dequeue();
    cout << c << c;  // output char twice
  }
  cout << endl;

  return 0;
}
