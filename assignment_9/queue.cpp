#include <iostream>
#include <string>

#define SIZE 100
using namespace std;

class QUEUE {
 private:
  char array[SIZE];
  int front;
  int rear; 
  int size;

 public:
  QUEUE(); 
  bool enqueue(char);
  char dequeue();
  bool isEmpty();
  bool isFull();
  char peek();
};

QUEUE::QUEUE() {
  front = 0;
  rear = -1;
  size = 0;
}

bool QUEUE::enqueue(char n) {
  if (isFull()) {
    cout << "queue full, cant enqueue." << endl;
    return false;
  }
  rear = (rear + 1) % SIZE;
  array[rear] = n;
  size++;
  return true;
}

char QUEUE::dequeue() {
  if (isEmpty()) {
    cout << "queue empty, cant dequeue." << endl;
    return '\0';  // return null char empty queue
  }
  char value = array[front];
  front = (front + 1) % SIZE;
  size--;
  return value;
}

bool QUEUE::isEmpty() { return size == 0; }

bool QUEUE::isFull() { return size == SIZE; }

char QUEUE::peek() {  // return front char without removing it
  if (!isEmpty()) {
    return array[front];
  }
  return '\0';  // null char if empty
}

int main() {
  QUEUE queue;
  string input;

  cout << "input string: ";
  cin >> input;

  // enqueue twice
  for (char c : input) {
    if (!queue.enqueue(c)) {
      break; //break when queu full
    }
    if (!queue.enqueue(c)) {
      break;  
    }
  }

  cout << "doubled output: ";

  // dequeue 
  while (!queue.isEmpty()) {
    char c = queue.dequeue();
    cout << c;
  }
  cout << endl;

  return 0;
}