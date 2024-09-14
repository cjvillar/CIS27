#include <iostream>

int main() {
    
    int arr[] = {12, 45, 23, 67, 34, 89, 56};  
    
    int min_val = arr[0];
    
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    std::cout << min_val << std::endl;
    return 0;
}