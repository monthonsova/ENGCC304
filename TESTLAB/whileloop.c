#include <stdio.h>

int main() {
    int n ;
    scanf( "%d" , &n ) ;

    int i = n ;
    while ( i > 1 ) {
        int isPrime = 1 ;

        int j = 2 ;
        while ( j < i ) {
            if ( i % j == 0 ) {
                isPrime = 0 ;
                break ;
            }
            j++ ;
        }

        if ( isPrime ) {
            printf( "%d " , i ) ;
        }

        i-- ;
    }

    printf( "\n" ) ;
    return 0 ;
}
