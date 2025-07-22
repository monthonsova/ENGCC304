#include <stdio.h>

int main() {
    int N;
    printf("Enter value:\n");
    if (scanf("%d", &N) != 1) {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Series: ");
    if (N % 2 == 1) {
        for (int i = 1; i <= N; i += 2) {
            printf("%d", i);
            if (i + 2 <= N) printf(" ");
        }
    } else {
        for (int i = N; i >= 0; i -= 2) {
            printf("%d", i);
            if (i - 2 >= 0) printf(" ");
        }
    }
    printf("\n");
    return 0;
} 