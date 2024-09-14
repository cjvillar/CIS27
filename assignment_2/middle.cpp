#include <iostream>

int main() {
    
    int arr[] = {12, 45, 23, 67, 34, 89, 56}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int middleValue;
    
    if (n % 2 == 0) {
        int middleIndex1 = n / 2 - 1;
        int middleIndex2 = n / 2;
        middleValue = (arr[middleIndex1] + arr[middleIndex2]) / 2;
    } else {
        int middleIndex = n / 2;
        middleValue = arr[middleIndex];
    }
    
    std::cout << "Middle value: " << middleValue << std::endl;
    return 0;
}
