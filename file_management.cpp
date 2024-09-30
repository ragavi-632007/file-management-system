#include <stdio.h>
#include <stdlib.h>


void createFile(char *filename);
void deleteFile(char *filename);
void copyFile(char *sourceFile, char *destFile);
void moveFile(char *sourceFile, char *destFile);

int main() {
    int choice;
    char filename[100], source[100], dest[100];

    while (1) {
        printf("\nFile Management System\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Copy a file\n");
        printf("4. Move a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 3:
                printf("Enter source file to copy: ");
                scanf("%s", source);
                printf("Enter destination file: ");
                scanf("%s", dest);
                copyFile(source, dest);
                break;
            case 4:
                printf("Enter source file to move: ");
                scanf("%s", source);
                printf("Enter destination file: ");
                scanf("%s", dest);
                moveFile(source, dest);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void createFile(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void deleteFile(char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Error deleting file!\n");
    }
}

void copyFile(char *sourceFile, char *destFile) {
    FILE *src = fopen(sourceFile, "r");
    FILE *dest = fopen(destFile, "w");
    if (src == NULL || dest == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied from '%s' to '%s'.\n", sourceFile, destFile);
    fclose(src);
    fclose(dest);
}

void moveFile(char *sourceFile, char *destFile) {
    if (rename(sourceFile, destFile) == 0) {
        printf("File moved from '%s' to '%s'.\n", sourceFile, destFile);
    } else {
        printf("Error moving file!\n");
        
    }
}
