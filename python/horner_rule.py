# Write a complete algorithm based on recursion utilizing Horner’s rule

def horner_rule(arr, x, n):
    if n == 0:
        return arr[n]
    return x * horner_rule(arr, x, n - 1) + arr[n]

arr = [2, 3, 4, 5, 6]
x = 2
n = len(arr) - 1
print(horner_rule(arr, x, n))

# Write a complete algorithm based on iteration utilizing Horner’s rule

def horner_rule(arr, x):
    result = arr[0]
    for i in range(1, len(arr)):
        result = result * x + arr[i]
    return result

arr = [2, 3, 4, 5, 6]
x = 2
print(horner_rule(arr, x))