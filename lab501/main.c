#include <stdio.h>

int main() {
    char emp_id[11];
    int hours;
    double rate, salary;

    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%10s", emp_id);

    printf("Input the working hrs: ");
    scanf("%d", &hours);

    printf("Salary amount/hr: ");
    scanf("%lf", &rate);

    salary = hours * rate;

    printf("Employees ID = %s\n", emp_id);
    printf("Salary = U$ %'.2f\n", salary); // ใช้ ' สำหรับ comma

    return 0;
}
