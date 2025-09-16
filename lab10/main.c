#include <stdio.h>

int main( void ) {
    char word[100] ;
    int len = 0 , i , j , isPalindrome = 1 ;

    printf( "Enter word:\n" ) ;
    scanf( "%s" , word ) ;

    while ( word[len] != '\0' ) {
        len++ ;
    }

    for ( i = 0 , j = len - 1 ; i < j ; i++ , j-- ) {
        if ( word[i] != word[j] ) {
            isPalindrome = 0 ;
            break ;
        }
    }

    if ( isPalindrome )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;
}
