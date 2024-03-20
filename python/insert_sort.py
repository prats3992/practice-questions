# Algorithm 12: InsertionSort(A)
# Input: An unsorted array A of size n.
# Output: Sorted array.
# 1 for j = 2 to n do
# 2 temp = A[j];
# 3 i = j − 1;
# 4 while i > 0 and A[i] > temp do
# 5 A[i + 1] = A[i] ; // The element A[i] is placed to the right
# 6 i = i − 1;
# 7 end
# 8 A[i + 1] = temp ; // A[j] is inserted at the right position
# 9 end

def insertion_sort(arr):
    for j in range(1, len(arr)):
        temp = arr[j]
        i = j - 1
        while i >= 0 and arr[i] > temp:
            arr[i + 1] = arr[i]
            i -= 1
        arr[i + 1] = temp
    return arr

# Insertion sort using recursion
def insertion_sort_rec(arr, n):
    if n <= 1:
        return
    insertion_sort_rec(arr, n - 1)
    last = arr[n - 1]
    j = n - 2
    while j >= 0 and arr[j] > last:
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = last
