#include <stdio.h>

int main() {
    int n ;
    scanf( "%d" , &n ) ;

    for ( int i = n ; i > 1 ; i-- ) {
        int isPrime = 1 ;

        for ( int j = 2 ; j < i ; j++ ) {
            if ( i % j == 0 ) {
                isPrime = 0 ;
                break ;
            }
        }

        if ( isPrime ) {
            printf( "%d " , i ) ;
        }
    }

    printf( "\n" ) ;
    return 0 ;
}
