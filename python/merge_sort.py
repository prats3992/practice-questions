# Algorithm 14: MergeSort(A)
# Input: An unsorted array A.
# Output: A sorted array.
# 1 n = A.size;
# 2 if n = 1 then
# 3 return A;
# 4 end
# 5 L = ∅ ; // An empty array/list of size n/2.
# 6 R = ∅ ; // An empty array/list of size n/2.
# 7 for i = 1 to dn/2e do
# 8 L[i] = A[i];
# 9 end
# 10 for i = dn/2e + 1 to n do
# 11 R[i − dn/2e] = A[i];
# 12 end
# 13 L = MergeSort(L) ; // Recursion call.
# 14 R = MergeSort(R) ; // Recursion call.
# 15 return Merge(L, R) ; 

def merge(L, R):
    n1 = len(L)
    n2 = len(R)
    A = []
    i = 0
    j = 0
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            A.append(L[i])
            i += 1
        else:
            A.append(R[j])
            j += 1
    while i < n1:
        A.append(L[i])
        i += 1
    while j < n2:
        A.append(R[j])
        j += 1
    return A

def merge_sort(A):
    n = len(A)
    if n == 1:
        return A
    L = []
    R = []
    for i in range(n//2):
        L.append(A[i])
    for i in range(n//2, n):
        R.append(A[i])
    L = merge_sort(L)
    R = merge_sort(R)
    return merge(L, R)

# Iterative version of merge sort
def merge_sort_iterative(A):
    n = len(A)
    current_size = 1
    while current_size < n:
        left = 0
        while left < n - 1:
            mid = min(left + current_size - 1, n - 1)
            right = min(left + 2 * current_size - 1, n - 1)
            L = A[left:mid+1]
            R = A[mid+1:right+1]
            A[left:right+1] = merge(L, R)
            left += 2 * current_size
        current_size *= 2
    return A