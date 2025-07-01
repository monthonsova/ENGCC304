# Lab 1

ตัวอย่างโปรแกรมรับชื่อและอายุจากผู้ใช้

## ตัวอย่างโค้ด

```cpp
#include <stdio.h>

int main() 
{
    char Name[50] ;
    int  Age ;
    printf( "Enter your name: " );
    scanf( "%s", Name);
    printf( "Enter your age: " ) ;
    scanf("%d", &Age);
    printf("- - - - - -\n");
    printf("Hello %s\n", Name); 
    printf("Age = %d\n", Age); 
    
}//end main function
```

## ตัวอย่างผลลัพธ์

![ตัวอย่างหน้าจอ](Screenshot%202025-07-01%20154934.png)