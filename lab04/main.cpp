#include <stdio.h>

int main() {
    char emp_id[11];
    int hours;
    double rate, salary;

    printf("Input the Employees ID(Max. 10 chars): \n");
    scanf("%10s", emp_id);

    printf("Input the working hrs: \n");
    scanf("%d", &hours);

    printf("Salary amount/hr: \n");
    scanf("%lf", &rate);

    salary = hours * rate;

    printf("Employees ID = %s\n", emp_id);
    printf("Salary = U$ %.2lf\n", salary);

    return 0;
} 