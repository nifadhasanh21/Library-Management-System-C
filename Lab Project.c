#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct library {
    char bk_name[30];
    char author[30];
    int pages;
    float price;
};

void addBook(struct library books[], int *count) {
    printf("\nEnter book name: ");
    scanf("%s", books[*count].bk_name);

    printf("Enter author name: ");
    scanf("%s", books[*count].author);

    printf("Enter pages: ");
    scanf("%d", &books[*count].pages);

    printf("Enter price: ");
    scanf("%f", &books[*count].price);

    (*count)++;
    printf("\nBook added successfully!\n");
}

void displayBooks(struct library books[], int count) {
    if (count == 0) {
        printf("\nNo books available!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nBook: %s | Author: %s | Pages: %d | Price: %.2f",
               books[i].bk_name, books[i].author, books[i].pages, books[i].price);
    }
}

void listBooksByAuthor(struct library books[], int count) {
    char author[30];
    printf("\nEnter author name: ");
    scanf("%s", author);

    for (int i = 0; i < count; i++) {
        if (strcmp(author, books[i].author) == 0) {
            printf("\nBook: %s | Pages: %d | Price: %.2f", books[i].bk_name, books[i].pages, books[i].price);
        }
    }
}

void searchBookByTitle(struct library books[], int count) {
    char title[30];
    printf("\nEnter book title: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(title, books[i].bk_name) == 0) {
            printf("\nBook found: %s | Author: %s | Pages: %d | Price: %.2f",
                   books[i].bk_name, books[i].author, books[i].pages, books[i].price);
        }
    }
}

int main() {
    struct library books[MAX_BOOKS];
    int bookCount = 0, choice;

    while (1) {
        printf("\n\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. List Books by Author");
        printf("\n4. Search Book by Title");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(books, &bookCount); break;
            case 2: displayBooks(books, bookCount); break;
            case 3: listBooksByAuthor(books, bookCount); break;
            case 4: searchBookByTitle(books, bookCount); break;
            case 5: return 0;
            default: printf("\nInvalid choice! Try again.");
        }
    }
}

