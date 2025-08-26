#include <stdio.h>

int isEven( int num ) {
    if ( num % 2 == 0 ) {
        return 1 ;
    }//end if
    return 0 ;
}//end function isEven

int main() {
    int n ;
    printf( "Enter N : " ) ;
    scanf( "%d" , &n ) ;

    int arr[n] ;
    for ( int i = 0 ; i < n ; i++ ) {
        printf( "Enter value[%d] : " , i ) ;
        scanf( "%d" , &arr[ i ] ) ;
    }//end for

    printf( "Index:  " ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        printf( "%2d " , i ) ;
    }//end for
    printf( "\n" ) ;

    printf( "Array:  " ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( isEven( arr[ i ] ) ) {
            printf( "%2d " , arr[ i ] ) ;
        }//end if
        else {
            printf( "%2s " , "#" ) ;
        }//end else
    }//end for
    printf( "\n" ) ;

    return 0 ;
}//end function main
