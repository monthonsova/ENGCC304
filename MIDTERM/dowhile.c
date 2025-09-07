#include <stdio.h>

int main() {
    int n ;
    scanf( "%d" , &n ) ;

    int i = n ;
    do {
        int isPrime = 1 ;

        int j = 2 ;
        if ( i > 2 ) {
            do {
                if ( i % j == 0 ) {
                    isPrime = 0 ;
                    break ;
                }
                j++ ;
            } while ( j < i ) ;
        }

        if ( isPrime ) {
            printf( "%d " , i ) ;
        }

        i-- ;
    } while ( i > 1 ) ;

    printf( "\n" ) ;
    return 0 ;
}
