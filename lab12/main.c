#include <stdio.h>

struct Student {
    char Name[50] ;
    char ID[10] ;
    float ScoreSub1 ;
    float ScoreSub2 ;
    float ScoreSub3 ;
    float ScoreSub4 ;
    float ScoreSub5 ;
} ;
typedef struct Student S ;

const char* grade( float score ) {
    if ( score >= 80 ) return "A" ;
    else if ( score >= 75 ) return "B+" ;
    else if ( score >= 70 ) return "B" ;
    else if ( score >= 65 ) return "C+" ;
    else if ( score >= 60 ) return "C" ;
    else if ( score >= 55 ) return "D+" ;
    else if ( score >= 50 ) return "D" ;
    else return "F" ;
}

int main( void ) {
    S students[3] ;
    int i ;

    printf( "Enter the details of 3 students :\n" ) ;

    for ( i = 0 ; i < 3 ; i++ ) {
        printf( "Student %d:\n" , i + 1 ) ;
        printf( "Name: \n" ) ;
        scanf( " %[^\n]" , students[i].Name ) ;
        printf( "ID: \n" ) ;
        scanf( "%s" , students[i].ID ) ;
        printf( "Scores in Subject 1: \n" ) ;
        scanf( "%f" , &students[i].ScoreSub1 ) ;
        printf( "Scores in Subject 2: \n" ) ;
        scanf( "%f" , &students[i].ScoreSub2 ) ;
        printf( "Scores in Subject 3: \n" ) ;
        scanf( "%f" , &students[i].ScoreSub3 ) ;
        printf( "Scores in Subject 4: \n" ) ;
        scanf( "%f" , &students[i].ScoreSub4 ) ;
        printf( "Scores in Subject 5: \n" ) ;
        scanf( "%f" , &students[i].ScoreSub5 ) ;
    }

    for ( i = 0 ; i < 3 ; i++ ) {
        float avg = ( students[i].ScoreSub1 + students[i].ScoreSub2 + students[i].ScoreSub3 + students[i].ScoreSub4 + students[i].ScoreSub5 ) / 5.0 ;

        printf( "\nStudent %d:\n" , i + 1 ) ;
        printf( "Name: %s\n" , students[i].Name ) ;
        printf( "ID: %s\n" , students[i].ID ) ;
        printf( "Scores: %.0f %.0f %.0f %.0f %.0f\n" ,
            students[i].ScoreSub1 ,
            students[i].ScoreSub2 ,
            students[i].ScoreSub3 ,
            students[i].ScoreSub4 ,
            students[i].ScoreSub5
        ) ;
        printf( "Grades: %s %s %s %s %s\n" ,
            grade( students[i].ScoreSub1 ) ,
            grade( students[i].ScoreSub2 ) ,
            grade( students[i].ScoreSub3 ) ,
            grade( students[i].ScoreSub4 ) ,
            grade( students[i].ScoreSub5 )
        ) ;
        printf( "Average Scores: %.1f\n" , avg ) ;
    }

    return 0 ;
}
