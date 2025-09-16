#include <stdio.h>

int main( void ) {
    int N ;
    printf( "Enter N :\n" ) ;
    scanf( "%d" , &N ) ;

    int arr[N] ;

    for ( int i = 0 ; i < N ; i++ ) {
        printf( "Enter value[%d] :\n" , i ) ;
        scanf( "%d" , &arr[i] ) ;
    }

    printf( "Index: " ) ;
    for ( int i = 0 ; i < N ; i++ ) {
        printf( "%2d " , i ) ;
    }
    printf( "\n" ) ;

    printf( "Array: " ) ;
    for ( int i = 0 ; i < N ; i++ ) {
        int n = arr[i] ;
        int prime = 1 ;

        if ( n < 2 ) {
            prime = 0 ;
        } else {
            for ( int j = 2 ; j < n ; j++ ) {
                if ( n % j == 0 ) {
                    prime = 0 ;
                    break ;
                }
            }
        }

        if ( prime )
            printf( "%d " , n ) ;
        else
            printf( " # " ) ;
    }
    printf( "\n" ) ;

    return 0 ;
}
