#include <stdio.h>
#include <string.h>

//แก้บัคมีข้อมูลตกค้างใน scanf
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void showMenu(void) {
    printf("\n=========== ตู้กดน้ำ & ขนม ตะพาบลอย ===========\n");
    printf("\nประเภทน้ำ\n");
    printf(" 1) โค้ก - 10 บาท\n");
    printf(" 2) น้ำเขียว - 12 บาท\n");
    printf(" 3) อเมริกาโน่ - 30 บาท\n");
    printf(" 4) ลาเต้ หวานเจี๊ยบ - 35 บาท\n");

    printf("\nขนม\n");
    printf(" 5) เมล็ดทานตะวัน - 13 บาท\n");
    printf(" 6) ถั่วแปบ - 20 บาท\n");
    printf(" 7) จิ้นส้มหมก - 15 บาท\n");
    printf("===============================================\n");
}

void payment(int total) {
    int money, paid = 0;
    int change, temp;

    int banknotes[] = { 500, 100, 50, 20 };
    int coins[] = { 10, 5, 1 };

    int bankCount[4] = { 0 };
    int coinCount[3] = { 0 };

    printf("\n=== ขั้นตอนการชำระเงิน ===\n");
    printf("ยอดที่ต้องชำระ: %d บาท\n", total);

    while (paid < total) {
        printf("ใส่ธนบัตรหรือเหรียญ (1,5,10,20,50,100,500): ");
        if (scanf("%d", &money) != 1) {
            printf("กรุณาใส่ตัวเลขเท่านั้น!\n");
            clearInputBuffer();
            continue;
        }

        if (money != 1 && money != 5 && money != 10 &&
            money != 20 && money != 50 && money != 100 && money != 500) {
            printf("ไม่รับธนบัตร/เหรียญนี้\n");
            continue;
        }

        paid += money;
        printf("ชำระแล้ว: %d บาท\n", paid);
        if (paid < total) {
            printf("ยังขาดอีก: %d บาท\n", total - paid);
        }
    }

    change = paid - total;
    printf("ชำระเสร็จสิ้น รวมจ่าย: %d บาท\n", paid);
    printf("เงินทอน: %d บาท\n", change);

    temp = change;
    for (int i = 0; i < 4; i++) {
        bankCount[i] = temp / banknotes[i];
        temp %= banknotes[i];
    }
    for (int i = 0; i < 3; i++) {
        coinCount[i] = temp / coins[i];
        temp %= coins[i];
    }

    if (change > 0) {
        printf("ทอนเป็น:\n");
        for (int i = 0; i < 4; i++) {
            if (bankCount[i] > 0) {
                printf(" ธนบัตร %d บาท x %d ใบ\n", banknotes[i], bankCount[i]);
            }
        }
        for (int i = 0; i < 3; i++) {
            if (coinCount[i] > 0) {
                printf(" เหรียญ %d บาท x %d เหรียญ\n", coins[i], coinCount[i]);
            }
        }
    }
    printf("===============================================\n");
    printf("ขอบคุณที่ใช้บริการ ตู้ตะพาบลอย\n");
}

int main(void) {
    int choice;
    char more = 'Y';
    int total = 0;
    int count = 0;

    char items[100][50]; //[สินค้าที่..,ชื่อ]
    int prices[100]; //[สินค้าที่...]

    showMenu();

    while (more == 'Y' || more == 'y') {
        printf("\nเลือกสินค้าตามหมายเลข: ");

        if (scanf("%d", &choice) != 1) {
            printf("กรุณาใส่ตัวเลขเท่านั้น!\n");
            clearInputBuffer();
            continue;
        }

        if (choice < 1 || choice > 7) {
            printf("ไม่มีสินค้านี้ กรุณาเลือกใหม่\n");
            continue;
        }

        if (choice == 1) {
            total += 10;
            strcpy(items[count], "โค้ก");
            prices[count] = 10;
            count++;
        } else if (choice == 2) {
            total += 12;
            strcpy(items[count], "น้ำเขียว");
            prices[count] = 12;
            count++;
        } else if (choice == 3) {
            total += 30;
            strcpy(items[count], "อเมริกาโน่");
            prices[count] = 30;
            count++;
        } else if (choice == 4) {
            total += 35;
            strcpy(items[count], "ลาเต้ หวานเจี๊ยบ");
            prices[count] = 35;
            count++;
        } else if (choice == 5) {
            total += 13;
            strcpy(items[count], "เมล็ดทานตะวัน");
            prices[count] = 13;
            count++;
        } else if (choice == 6) {
            total += 20;
            strcpy(items[count], "ถั่วแปบ");
            prices[count] = 20;
            count++;
        } else if (choice == 7) {
            total += 15;
            strcpy(items[count], "จิ้นส้มหมก");
            prices[count] = 15;
            count++;
        } 

        do {
            printf("จะเอาเพิ่มไหม? (Y/N): ");
            scanf(" %c", &more);
            clearInputBuffer();
            if (more != 'Y' && more != 'y' && more != 'N' && more != 'n') {
                printf("กรุณาพิมพ์เฉพาะ Y หรือ N เท่านั้น!\n");
            }
        } while (more != 'Y' && more != 'y' && more != 'N' && more != 'n');
    }

    printf("\nนี่คือรายการทั้งหมดที่คุณเลือก:\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s - %d บาท\n", i+1 , items[i], prices[i]);
    }
    printf("รวมทั้งหมด: %d บาท\n", total);

    char pay;
    do {
        printf("ต้องการจะชำระเงินเลยหรือไม่? (Y/N): ");
        scanf(" %c", &pay);
        clearInputBuffer();
        if (pay != 'Y' && pay != 'y' && pay != 'N' && pay != 'n') {
            printf("กรุณาพิมพ์เฉพาะ Y หรือ N เท่านั้น!\n");
        }
    } while (pay != 'Y' && pay != 'y' && pay != 'N' && pay != 'n');

    if (pay == 'N' || pay == 'n') {
        printf("ทำรายการไม่สำเร็จ\n");
        printf("===============================================\n");
        printf("ขอบคุณที่ใช้บริการ ตู้ตะพาบลอย\n");
        return 0;
    }

    payment(total);

    return 0;
}
