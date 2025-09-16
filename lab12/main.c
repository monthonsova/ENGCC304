#include <stdio.h>

struct Student {
    char Name[20] ;
    char ID[5] ;
    float ScoreSub1 ;
    float ScoreSub2 ;
    float ScoreSub3 ;
    float ScoreSub4 ;
    float ScoreSub5 ;
} typedef S ;

void grade( float score , char result[3] ) {
    if ( score >= 80 ) {
        result[0] = 'A' ; result[1] = '\0' ;
    }
    else if ( score >= 75 ) {
        result[0] = 'B' ; result[1] = '+' ; result[2] = '\0' ;
    }
    else if ( score >= 70 ) {
        result[0] = 'B' ; result[1] = '\0' ;
    }
    else if ( score >= 65 ) {
        result[0] = 'C' ; result[1] = '+' ; result[2] = '\0' ;
    }
    else if ( score >= 60 ) {
        result[0] = 'C' ; result[1] = '\0' ;
    }
    else if ( score >= 55 ) {
        result[0] = 'D' ; result[1] = '+' ; result[2] = '\0' ;
    }
    else if ( score >= 50 ) {
        result[0] = 'D' ; result[1] = '\0' ;
    }
    else {
        result[0] = 'F' ; result[1] = '\0' ;
    }
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
        float avg = ( students[i].ScoreSub1 + students[i].ScoreSub2 +
                      students[i].ScoreSub3 + students[i].ScoreSub4 +
                      students[i].ScoreSub5 ) / 5.0 ;

        char g1[3], g2[3], g3[3], g4[3], g5[3] ;
        grade( students[i].ScoreSub1 , g1 ) ;
        grade( students[i].ScoreSub2 , g2 ) ;
        grade( students[i].ScoreSub3 , g3 ) ;
        grade( students[i].ScoreSub4 , g4 ) ;
        grade( students[i].ScoreSub5 , g5 ) ;

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
        printf( "Grades: %s %s %s %s %s\n" , g1 , g2 , g3 , g4 , g5 ) ;
        printf( "Average Scores: %.1f\n" , avg ) ;
    }

    return 0 ;
}
