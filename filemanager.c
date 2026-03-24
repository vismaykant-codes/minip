#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX 50

struct File {
    char name[50];
    int size;
    char date[20];
    char createdBy[30];
};

struct File fileList[MAX];
int totalFiles = 0;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showHeader() {
    setColor(11);
    printf("\n==============================================================\n");
    printf("               FILE MANAGEMENT SYSTEM\n");
    printf("==============================================================\n");
    setColor(7);
}

void showDashboard() {
    system("cls");
    showHeader();

    printf("\n%-25s %-30s\n", "FILES", "DETAILS");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < totalFiles; i++) {
        printf("%-25s", fileList[i].name);

        if (i == 0)
            printf("Name: %s\n", fileList[i].name);
        else if (i == 1)
            printf("Size: %d KB\n", fileList[i].size);
        else if (i == 2)
            printf("Date: %s\n", fileList[i].date);
        else
            printf("\n");
    }

    printf("\n--------------------------------------------------------------\n");
    setColor(10);
    printf("1. Add  2. Delete  3. Sort  4. Search  5. Exit");
    setColor(7);
}

void addFile() {
    if (totalFiles >= MAX) {
        printf("\nStorage is full!");
        getch();
        return;
    }

    system("cls");
    showHeader();

    printf("\nEnter file name: ");
    scanf("%s", fileList[totalFiles].name);

    printf("Enter file size (KB): ");
    scanf("%d", &fileList[totalFiles].size);

    printf("Enter date: ");
    scanf("%s", fileList[totalFiles].date);

    printf("Created by: ");
    scanf("%s", fileList[totalFiles].createdBy);

    totalFiles++;

    printf("\nFile added successfully!");
    getch();
}

void deleteFile() {
    char name[50];
    int index = -1;

    system("cls");
    showHeader();

    printf("\nEnter file name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < totalFiles; i++) {
        if (strcmp(fileList[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nFile not found!");
    } else {
        for (int i = index; i < totalFiles - 1; i++) {
            fileList[i] = fileList[i + 1];
        }
        totalFiles--;
        printf("\nFile deleted successfully!");
    }

    getch();
}

void sortFiles() {
    int choice;
    struct File temp;

    system("cls");
    showHeader();

    printf("\n1. Sort by Name\n2. Sort by Size\nEnter choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < totalFiles - 1; i++) {
        for (int j = 0; j < totalFiles - i - 1; j++) {
            if ((choice == 1 && strcmp(fileList[j].name, fileList[j + 1].name) > 0) ||
                (choice == 2 && fileList[j].size > fileList[j + 1].size)) {

                temp = fileList[j];
                fileList[j] = fileList[j + 1];
                fileList[j + 1] = temp;
            }
        }
    }

    printf("\nFiles sorted successfully!");
    getch();
}

void searchFile() {
    char name[50];
    int found = 0;

    system("cls");
    showHeader();

    printf("\nEnter file name to search: ");
    scanf("%s", name);

    for (int i = 0; i < totalFiles; i++) {
        if (strcmp(fileList[i].name, name) == 0) {
            printf("\nFile found!\n");
            printf("Name: %s\n", fileList[i].name);
            printf("Size: %d KB\n", fileList[i].size);
            printf("Date: %s\n", fileList[i].date);
            printf("Created by: %s\n", fileList[i].createdBy);
            found = 1;
        }
    }

    if (!found)
        printf("\nFile not found!");

    getch();
}

int main() {
    int choice;

    while (1) {
        showDashboard();

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addFile(); break;
            case 2: deleteFile(); break;
            case 3: sortFiles(); break;
            case 4: searchFile(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
}   