"""Given an array of integers, determine whether it contains a Pythagorean triplet. Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2."""


# Useless Approach / Most Basic Approach
def pythogorean_triplet(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                x = arr[i] ** 2
                y = arr[j] ** 2
                z = arr[k] ** 2
                if (x + y == z) or (y + z == x) or (x + z == y):
                    return True
    return False

# Time Complexity: O(n^3)

# Efficient Approach


def pythogorean_tripling(arr):
    n = len(arr)
    for i in range(n):
        arr[i] = arr[i] ** 2
    arr.sort()
    for i in range(n-1, 1, -1):
        l = 0
        r = i - 1
        while l < r:
            if arr[l] + arr[r] == arr[i]:
                return True
            else:
                if arr[l] + arr[r] < arr[i]:
                    l += 1
                else:
                    r -= 1
    return False
# Time Complexity: O(n^2)

if __name__ == "__main__":
    print(pythogorean_triplet([3, 5, 12, 5, 13]))  # True
    print(pythogorean_triplet([3, 5, 12, 5, 15]))  # False
    print(pythogorean_tripling([3, 5, 12, 5, 13]))  # True
    print(pythogorean_tripling([3, 5, 12, 5, 15]))  # False
