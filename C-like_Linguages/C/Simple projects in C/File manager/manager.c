#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void create_file(const char *filename){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error creating file %s\n", filename);
        return;
    }
    printf("File %s created successfully\n", filename);
    fclose(file);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error reading file %s\n", filename);
        return;
    }
    char ch;
    printf("Content of %s:\n", filename);
    while((ch = fgetc(file)) != EOF)
 {
     putchar(ch);
 }
    printf("\n");
    fclose(file);
}
void edit_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s for editing\n", filename);
        return;
    }
    printf("Enter new content for %s (end with EOF):\n", filename);
    char ch;
    while((ch = getchar()) != EOF){
        fputc(ch, file);
    }
    fclose(file);
    printf("File %s edited successfully\n", filename);
}
void delete_file(const char *filename){
    if(remove(filename) == 0) {
        printf("File %s deleted successfully\n", filename);
    }
    else {
        printf("Error deleting file %s\n", filename);
    }
}
int main(){
    char filename[MAX_FILENAME_LENGTH];
    int choice;
    while(1){
        printf("\n=== File Manager ===\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Edit a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

    switch (choice){
        case 1:
            printf("Enter filename to create: ");
            fgets(filename, MAX_FILENAME_LENGTH, stdin);
            filename[strcspn(filename, "\n")] = 0;
            create_file(filename);
            break;

        case 2:
        printf("Enter filename to read: ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = 0;
        read_file(filename);
        break;

        case 3:
        printf("Enter filename to edit: ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = 0;
        edit_file(filename);
        break;

        case 4:
        printf("Enter filename to delete: ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = 0;
        delete_file(filename);
        break;

        case 5:
        printf("Exiting File Manager\n");
        return 0;
        default:
        printf("Invalid choice. Please try again.\n");
        
    }
    }
    return 0;
}