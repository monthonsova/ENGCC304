#include <stdio.h>
#include <string.h>

//แก้บัคมีข้อมูลตกค้างใน scanf
void clearInputBuffer( void ) {
    int c ;
    while ( ( c = getchar() ) != '\n' && c != -1 ) {
    }//end while
}//end function clearInputBuffer

void showMenu( char items[ 7 ][ 50 ] , int prices[ 7 ] , int stock[ 7 ] ) {
    printf( "\n=========== ตู้กดน้ำ & ขนม ตะพาบลอย ===========\n" ) ;
    for ( int i = 0 ; i < 7 ; i++ ) {
        printf( " %d) %s - %d บาท (เหลือ %d ชิ้น)\n" , i + 1 , items[ i ] , prices[ i ] , stock[ i ] ) ;
    }//end for
    printf( "===============================================\n" ) ;
}//end function showMenu

void payment( int total ) {
    int money , paid = 0 ;
    int change , temp ;

    int banknotes[] = { 500 , 100 , 50 , 20 } ;
    int coins[] = { 10 , 5 , 1 } ;

    int bankCount[ 4 ] = { 0 } ;
    int coinCount[ 3 ] = { 0 } ;

    printf( "\n=== ขั้นตอนการชำระเงิน ===\n" ) ;
    printf( "ยอดที่ต้องชำระ: %d บาท\n" , total ) ;

    while ( paid < total ) {
        printf( "ใส่ธนบัตรหรือเหรียญ (1,5,10,20,50,100,500): " ) ;
        if ( scanf( "%d" , &money ) != 1 ) {
            printf( "กรุณาใส่ตัวเลขเท่านั้น!\n" ) ;
            clearInputBuffer() ;
            continue ;
        }//end if

        if ( money != 1 && money != 5 && money != 10 &&
             money != 20 && money != 50 && money != 100 && money != 500 ) {
            printf( "ไม่รับธนบัตร/เหรียญนี้\n" ) ;
            continue ;
        }//end if

        paid += money ;
        printf( "ชำระแล้ว: %d บาท\n" , paid ) ;
        if ( paid < total ) {
            printf( "ยังขาดอีก: %d บาท\n" , total - paid ) ;
        }//end if
    }//end while

    change = paid - total ;
    printf( "ชำระเสร็จสิ้น รวมจ่าย: %d บาท\n" , paid ) ;
    printf( "เงินทอน: %d บาท\n" , change ) ;

    temp = change ;
    for ( int i = 0 ; i < 4 ; i++ ) {
        bankCount[ i ] = temp / banknotes[ i ] ;
        temp %= banknotes[ i ] ;
    }//end for
    for ( int i = 0 ; i < 3 ; i++ ) {
        coinCount[ i ] = temp / coins[ i ] ;
        temp %= coins[ i ] ;
    }//end for

    if ( change > 0 ) {
        printf( "ทอนเป็น:\n" ) ;
        for ( int i = 0 ; i < 4 ; i++ ) {
            if ( bankCount[ i ] > 0 ) {
                printf( " ธนบัตร %d บาท x %d ใบ\n" , banknotes[ i ] , bankCount[ i ] ) ;
            }//end if
        }//end for
        for ( int i = 0 ; i < 3 ; i++ ) {
            if ( coinCount[ i ] > 0 ) {
                printf( " เหรียญ %d บาท x %d เหรียญ\n" , coins[ i ] , coinCount[ i ] ) ;
            }//end if
        }//end for
    }//end if


}//end function payment

int main( void ) {
    int choice ;
    char more = 'Y' ;
    int total = 0 ;
    int count = 0 ;

    char orderItems[ 100 ][ 50 ] ;
    int orderPrices[ 100 ] ;

    char items[ 7 ][ 50 ] = {
        "โค้ก" , "น้ำเขียว" , "อเมริกาโน่" ,
        "ลาเต้ หวานเจี๊ยบ" , "เมล็ดทานตะวัน" ,
        "ถั่วแปบ" , "จิ้นส้มหมก"
    } ;

    int prices[7] = { 10 , 12 , 30 , 35 , 13 , 20 , 15 } ;
    int stock[7]  = { 10 , 10 , 10 , 10 , 10 , 10 , 10 } ;

    showMenu( items , prices , stock ) ;

    while ( more == 'Y' || more == 'y' ) {
        printf( "\nเลือกสินค้าตามหมายเลข: " ) ;

        if ( scanf( "%d" , &choice ) != 1 ) {
            printf( "กรุณาใส่ตัวเลขเท่านั้น!\n" ) ;
            clearInputBuffer() ;
            continue ;
        }//end if

        if ( choice < 1 || choice > 7 ) {
            printf( "ไม่มีสินค้านี้ กรุณาเลือกใหม่\n" ) ;
            continue ;
        }//end if

        if ( stock[ choice - 1 ] <= 0 ) {
            printf( "ขออภัย %s หมดแล้ว!\n" , items[ choice - 1 ] ) ;
            continue ;
        }//end if

        total += prices[ choice - 1 ] ;
        strcpy( orderItems[ count ] , items[ choice - 1 ] ) ;
        orderPrices[ count ] = prices[ choice - 1 ] ;
        stock[ choice - 1 ]-- ; // ลด stock
        count++ ;

        do {
            printf( "จะเอาเพิ่มไหม? (Y/N): " ) ;
            scanf( " %c" , &more ) ;
            clearInputBuffer() ;
            if ( more != 'Y' && more != 'y' && more != 'N' && more != 'n' ) {
                printf( "กรุณาพิมพ์เฉพาะ Y หรือ N เท่านั้น!\n" ) ;
            }//end if
        } while ( more != 'Y' && more != 'y' && more != 'N' && more != 'n' ) ;
    }//end while

    printf( "\n=== นี่คือรายการทั้งหมดที่คุณเลือก ===\n" ) ;
    for ( int i = 0 ; i < count ; i++ ) {
        printf( "%d) %s - %d บาท\n" , i + 1 , orderItems[ i ] , orderPrices[ i ] ) ;
    }//end for
    printf( "รวมทั้งหมด: %d บาท\n" , total ) ;

    char pay ;
    do {
        printf( "ต้องการจะชำระเงินเลยหรือไม่? (Y/N): " ) ;
        scanf( " %c" , &pay ) ;
        clearInputBuffer() ;
        if ( pay != 'Y' && pay != 'y' && pay != 'N' && pay != 'n' ) {
            printf( "กรุณาพิมพ์เฉพาะ Y หรือ N เท่านั้น!\n" ) ;
        }//end if
    } while ( pay != 'Y' && pay != 'y' && pay != 'N' && pay != 'n' ) ;

    if ( pay == 'N' || pay == 'n' ) {
        printf( "ทำรายการไม่สำเร็จ\n" ) ;
        printf( "===============================================\n" ) ;
        printf( "ขอบคุณที่ใช้บริการ ตู้ตะพาบลอย\n" ) ;
        return 0 ;
    }//end if

    payment( total ) ;

    printf( "\n=== Stock ที่เหลือหลังการซื้อ ===\n" ) ;
    for ( int i = 0 ; i < 7 ; i++ ) {
        printf( "%s เหลือ %d ชิ้น\n" , items[ i ] , stock[ i ] ) ;
    }//end for

    printf( "===============================================\n" ) ;
    printf( "ขอบคุณที่ใช้บริการ ตู้ตะพาบลอย\n" ) ;
    return 0 ;
}//end function main