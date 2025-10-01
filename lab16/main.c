#include <stdio.h>

int main(void) {
    int arr[] = { 15, 7, 25, 3, 73, 32, 45 };
    int n = 7;
    int i, j, temp, pos = -1;

    printf("Old Series : ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");

    // Bubble Sort (เรียงจากน้อยไปมาก)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("New Series : ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
        if (arr[i] == 32) pos = i;
    }
    printf("\n");

    printf("Pos of 32 : %d\n", pos);

    return 0;
}
