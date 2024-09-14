def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

array = [1, 3, 5, 2, 5, 9, 8]
sorted_array = bubble_sort(array)
print(sorted_array)
