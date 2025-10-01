#include <stdio.h>

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main(void) {
    int arr[100];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter value:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Index: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Min : %d\n", findMin(arr, n));
    printf("Max : %d\n", findMax(arr, n));

    return 0;
}
