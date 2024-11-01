#include <iostream>



int main(){

int arr[6] = {1,2,3,4,5,6};
for (int i : arr){
    std::cout << i << ' ';
    std::cout << '\n';
}

return 0;
}