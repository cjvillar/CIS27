// Initial array
int arr[] = {5, 3};

// check if element at pos 0 is greater
// than element at pos 1
//if so swap by holding  arr[0] in temp
if (arr[0] > arr[1]) {
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp; //swap 5 for 3
}

// After swapping
// arr = {3, 5}