#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int year;
};

void addBook(struct Book books[], int* count) {
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", books[*count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", books[*count].author);

    printf("Enter Year: ");
    scanf("%d", &books[*count].year);

    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(struct Book books[], int count, char title[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) { //นำมาเช็คว่ามี title นี้ใน books.title นั้นๆหรือไม่ ถ้ามีจะ == 0 
            printf("Book ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books available.\n");
    }
    else {
        for (int i = 0; i < count; i++) {
            printf("Book ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n\n", books[i].year);
        }
    }
}

int main() {
    struct Book books[100];
    int count = 0;
    int choice;
    char title[100];

    while (1) {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(books, &count);
        }
        else if (choice == 2) {
            printf("Enter Title to Search: ");
            scanf(" %[^\n]", title);
            searchBook(books, count, title);
        }
        else if (choice == 3) {
            displayBooks(books, count);
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}
