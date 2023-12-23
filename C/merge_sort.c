#include <stdio.h>
#define N 10

//merge two sorted halves of an array
void sort(int arr1[], int arr2[], int s, int mid, int e) {
    int i = s; //current index first half
    int j = mid + 1; //current index second half
    int k = s; //current index combined

    //merge the two halves while sorting
    while (i <= mid && j <= e) 
    {
        if (arr1[i] <= arr1[j]) {
            arr2[k] = arr1[i];
            i++;
        } else {
            arr2[k] = arr1[j];
            j++;
        }
        k++;
    }

    //get the remaining elements from the first half, if any
    while (i <= mid) {
        arr2[k] = arr1[i];
        i++;
        k++;
    }

    //get the remaining elements from the second half, if any
    while (j <= e) {
        arr2[k] = arr1[j];
        j++;
        k++;
    }

    //store the merged elements back to the original array
    for (int x = s; x <= e; x++) {
        arr1[x] = arr2[x];
    }
}

//recursive merge sort
void mergesort(int arr1[], int arr2[], int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        //sort the half 1
        mergesort(arr1, arr2, s, mid);

        //sort the half 2
        mergesort(arr1, arr2, mid + 1, e);

        //combine both half
        sort(arr1, arr2, s, mid, e);
    }
}

int main() {
    int arr1[N], arr2[N];
    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arr1[i]);
    }
    printf("Given Array: ");
    for (int i = 0; i < N; i++) 
    {
        printf("%d ", arr1[i]);
    }
    mergesort(arr1, arr2, 0, N - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < N; i++) 
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
