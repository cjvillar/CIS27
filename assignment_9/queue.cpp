#include <iostream>
#include <string>

#define SIZE 5

using namespace std;

class QUEUE {
 private:
  char array[SIZE];
  int front, rear;

 public:
  QUEUE();  // default constructor
  bool enqueue(char);
  char dequeue();
  bool isEmpty();
  bool isFull();
  char peek();
};

QUEUE::QUEUE() {
  front = 0;
  rear = -1;
}

bool QUEUE::enqueue(char n) {
  if (isFull()) {
    cout << "Queue is full, cant enqueue." << endl;
    return false;
  }
  rear = (rear + 1) % SIZE;
  array[rear] = n;
  return true;
}

char QUEUE::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty, cant dequeue." << endl;
    return '\0';  // return null char empty queue
  }
  char value = array[front];
  front = (front + 1) % SIZE;
  return value;
}

bool QUEUE::isEmpty() { return front == (rear + 1) % SIZE; }

bool QUEUE::isFull() { return (rear + 1) % SIZE == front; }

char QUEUE::peek() {  // return front char without removing it
  if (!isEmpty()) {
    return array[front];
  }
  return '\0';  // null char if empty
}

int main() {
  QUEUE queue;
  string input;

  cout << "Please input a string: ";
  cin >> input;

  // enqueue all string chars into queue
  for (char c : input) {
    if (!queue.enqueue(c)) {
      break;  //queue full
    }
  }

  cout << "Queued string in original order: ";

  // dequeue all chars in the original order
  while (!queue.isEmpty()) {
    cout << queue.dequeue();
  }

  cout << endl;

  return 0;
}
