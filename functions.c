#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "datatypes.h"

struct Book books[100];  
int bookCount = 0; 
// Hien thi Menu
void showMenu() {
    printf("==== Quan Li Thu Vien Sach ====\n");
    printf("========MENU========\n");
    printf("1. Hien thi danh sach sach\n");
    printf("2. Them sach moi\n");
    printf("3. Sua thong tin sach\n");
    printf("4. Xoa sach\n");
    printf("5. Cap nhat thong tin sach\n");
    printf("6. Tim kiem sach\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
// Them sach moi
void addBook() {
    if (bookCount >= 100) {
        printf("Danh sach da day.\n");
        return;
    }
    struct Book newBook;
    printf("Moi ban nhap ten sach: ");
    getchar(); 
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  
    printf("Nhap tac gia: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 
    printf("Nhap nam xuat ban: ");
    scanf("%d", &newBook.year);

    printf("Nhap gia sach: ");
    scanf("%d", &newBook.price);

    books[bookCount] = newBook;
    bookCount++;

    printf("Ban da them sach thanh cong!\n");
}
// Hien thi danh sach sach
void displayBooks() {
    if (bookCount == 0) {
        printf("Chua co sach nao trong danh sach.\n");
        return;
    }

    printf("\nDanh sach sach:\n");
    printf("%-30s %-30s %-10s %-10s\n", "Ten sach", "Tac gia", "Nam XB", "Gia");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%-30s %-30s %-10d %-10d\n", books[i].title, books[i].author, books[i].year, books[i].price);
    }
}
