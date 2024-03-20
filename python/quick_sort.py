# Algorithm 18: Partition(A, left,right)
# Input: An unsorted array A, and two indices, left and right of A.
# Output: A modified array A and an index m such that A[i] ≤ A[m] for i ≤ m and A[m] < A[j] for
# m + 1 ≤ j.
# 1 pivot = A[left];
# 2 L = left;
# 3 R = right;
# 4 while L < R do
# 5 while A[L] ≤ pivot and L ≤ right do
# 6 L = L + 1;
# 7 end
# 8 while A[R] > pivot and R ≥ left do
# 9 R = R − 1;
# 10 end
# 11 if L < R then
# 12 A[L] ↔ A[R] ; // Swap.
# 13 end
# 14 end
# 15 middle = R;
# 16 A[middle] ↔ A[left] ; // Swap.
# 17 return middle

# Algorithm 19: QuickSort(A, left,right)
# Input: An unsorted array A, and two indices, left and right of A: Initially, left = 1 and right = n
# Output: A sorted array A.
# 1 if left < right then
# 2 middle = Partition(A, left,right) ; // Call Algorithm 18.
# 3 Quicksort(A, left, middle − 1) ; // Recursion call.
# 4 Quicksort(A, middle + 1,right); // Recursion call.
# 5 end

def partition(arr, left, right):
    pivot = arr[left]
    L = left
    R = right
    while L < R:
        while arr[L] <= pivot and L <= right:
            L = L + 1
        while arr[R] > pivot and R >= left:
            R = R - 1
        if L < R:
            arr[L], arr[R] = arr[R], arr[L]
            print(arr)  # Print array after each swap
    middle = R
    arr[middle], arr[left] = arr[left], arr[middle]
    print(arr)  # Print array after partitioning
    return middle

def quick_sort(arr, left, right):
    if left < right:
        middle = partition(arr, left, right)
        print("Middle:", middle)
        quick_sort(arr, left, middle - 1)
        print("Left:", arr[left:middle])
        quick_sort(arr, middle + 1, right)
        print("Right:", arr[middle + 1:right + 1])
    return arr

arr = [4, 3, 8, 5, 2, 7, 1, 6]
print("Original array:", arr)
sorted_arr = quick_sort(arr, 0, len(arr) - 1)
print("Sorted array:", sorted_arr)
