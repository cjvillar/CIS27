#include <iostream>

int main() {
    
    int arr[] = {12, 45, 23, 67, 34, 89, 56};  
    
    int max_val = arr[0];
    
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    std::cout << max_val << std::endl;
    return 0;
}