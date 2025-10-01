#include <stdio.h>

int main() {
    char filename[100];
    FILE* fp;
    char word[100];
    int count = 0;

    printf("Enter file name:\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    // อ่านทีละ "คำ" โดยแยกด้วยช่องว่าง เว้นบรรทัด อัตโนมัติ
    while (fscanf(fp, "%s", word) == 1) {
        count++;
    }

    printf("Total number of words in '%s' : %d words\n", filename, count);

    fclose(fp);
    return 0;
}
