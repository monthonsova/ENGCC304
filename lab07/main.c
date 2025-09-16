#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ) {
    int cmd ;

    srand( time( NULL ) ) ;

    while ( 1 ) {
        printf( "Do you want to play game (1=play,-1=exit) :\n" ) ;

        if ( scanf( "%d" , &cmd ) != 1 ) {
            scanf( "%*s" ) ;
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
            continue ;
        }

        if ( cmd == -1 ) {
            printf( "\nSee you again.\n" ) ;
            return 0 ;
        } else if ( cmd != 1 ) {
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
            continue ;
        }

        {
            int target = rand() % 100 + 1 ;
            int score  = 100 ;
            int low    = 1 , high = 100 ;
            int guess ;

            printf( "\n(Score=100)\n\n" ) ;
            
            while ( 1 ) {
                printf( "Guess the winning number (%d-%d) :\n" , low , high ) ;

                if ( scanf( "%d" , &guess ) != 1 ) {
                    scanf( "%*s" ) ;
                    printf( "\n" ) ;
                    continue ;
                }

                if ( guess == target ) {
                    printf( "\nThat is correct! The winning number is %d.\n\n" , target ) ;
                    printf( "Score this game: %d\n\n" , score ) ;
                    break ;
                }

                score -= 10 ;

                if ( score <= 0 ) {
                    printf( "\nYou lose! The winning number was %d.\n\n" , target ) ;
                    break ;
                }

                if ( guess < low ) {
                    printf( "\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n" , low , score ) ;
                } else if ( guess > high ) {
                    printf( "\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n" , high , score ) ;
                } else if ( guess < target ) {
                    low = guess + 1 ;
                    printf( "\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n" , guess , score ) ;
                } else {
                    high = guess - 1 ;
                    printf( "\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n" , guess , score ) ;
                }
            }
        }
    }
}
