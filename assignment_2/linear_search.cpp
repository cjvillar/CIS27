#include <iostream>

int main() {
  int arr[10] = {1,2,30,4,5,6,74,80,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int target = 4;

  for (int i = 0; i < n; i++)
    if (arr[i] == target ){
        std::cout << "Targe: " << target << ", index: " << i << std::endl;
    }
  return 0;
}