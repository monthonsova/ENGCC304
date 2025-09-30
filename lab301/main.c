#include <stdio.h>

int main(void) {
    float H, W, Area;

    printf("Enter height (H): ");
    scanf("%f", &H);

    printf("Enter width (W): ");
    scanf("%f", &W);

    Area = (H * W) / 2;

    printf("Area = %.1f\n", Area);

    return 0;
}
