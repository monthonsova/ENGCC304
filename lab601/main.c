#include <stdio.h>

int main() {
    int num;
    printf("User Input : ");
    scanf("%d", &num);

    if (num == 0) printf("Result : zero\n");
    else if (num == 1) printf("Result : one\n");
    else if (num == 2) printf("Result : two\n");
    else if (num == 3) printf("Result : three\n");
    else if (num == 4) printf("Result : four\n");
    else if (num == 5) printf("Result : five\n");
    else if (num == 6) printf("Result : six\n");
    else if (num == 7) printf("Result : seven\n");
    else if (num == 8) printf("Result : eight\n");
    else if (num == 9) printf("Result : nine\n");
    else if (num == 10) printf("Result : ten\n");
    else if (num == 11) printf("Result : eleven\n");
    else if (num == 12) printf("Result : twelve\n");
    else printf("out of range\n");

    return 0;
}
