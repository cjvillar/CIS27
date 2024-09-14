#include <iostream>

int main() {
  int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0; i < sizeof(myArray)/sizeof(myArray[0]); i++)
    std::cout << myArray[i] << std::endl;
  return 0;
}