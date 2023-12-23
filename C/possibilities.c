#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int start, int end, int **result, int *count) {
    if (start == end) {
        result[*count] = (int *)malloc(sizeof(int) * (end + 1));  // Allocate space for each permutation
        for (int i = 0; i <= end; i++) {
            result[*count][i] = arr[i];  // Directly assign the array elements
        }
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(arr + start, arr + i);
            permute(arr, start + 1, end, result, count);
            swap(arr + start, arr + i);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for permutations
    int **result = (int **)malloc(sizeof(int *) * factorial(n));
    
    int count = 0;
    permute(arr, 0, n - 1, result, &count);

    printf("Permutations:\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);  // Free the memory allocated for each permutation
    }

    free(result);  // Free the array of permutations
    free(arr);     // Free the array entered by the user

    return 0;
}
