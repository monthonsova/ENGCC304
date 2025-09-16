#include <stdio.h>

int main( void ) {
    int position , years , projects ;
    float baseSalary = 0 , expBonus = 0 , specialBonus = 0 , netSalary = 0 ;

    printf( "Enter Position (1=Junior, 2=Mid-Level, 3=Senior): " ) ;
    scanf( "%d" , &position ) ;
    printf( "Enter Years of Experience: " ) ;
    scanf( "%d" , &years ) ;
    printf( "Enter Number of Projects Completed this Year: " ) ;
    scanf( "%d" , &projects ) ;

    if ( position == 1 ) {
        baseSalary = 20000 ;
    } else if ( position == 2 ) {
        baseSalary = 35000 ;
    } else if ( position == 3 ) {
        baseSalary = 50000 ;
    } else {
        printf( "Invalid position!\n" ) ;
        return 0 ;
    }

    if ( years < 1 ) {
        expBonus = 0 ;
    } else if ( years >= 1 && years <= 3 ) {
        expBonus = baseSalary * 0.10 ;
    } else if ( years >= 4 && years <= 5 ) {
        expBonus = baseSalary * 0.15 ;
    } else if ( years > 5 ) {
        expBonus = baseSalary * 0.20 ;
    }

    if ( projects > 5 ) {
        specialBonus = baseSalary * 0.05 ;
    }

    netSalary = baseSalary + expBonus + specialBonus ;

    printf( "Base Salary: %.0f THB\n" , baseSalary ) ;
    printf( "Experience Bonus: %.0f THB\n" , expBonus ) ;
    printf( "Special Bonus: %.0f THB\n" , specialBonus ) ;
    printf( "Net Salary: %.0f THB\n" , netSalary ) ;

    return 0 ;
}
s