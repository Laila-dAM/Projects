#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char director[100];
    int year;
} Movie;

typedef struct {
    Movie *movies;
    int size;
    int capacity;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db, int capacity){
    db->movies = (Movie *)malloc(sizeof(Movie)* capacity);
    db->size = 0;
    db->capacity = capacity;
}

void freeDatabase(MovieDatabase *db){
    free(db->movies);
}
void saveDatabase(MovieDatabase *db, const char *filename){
    FILE *file = fopen(filename, "wb");
    fwrite(&db->size, sizeof(int), 1, file);
    fwrite(db->movies, sizeof(Movie), db->size, file);
    fclose(file);
}
void loadDatabase(MovieDatabase *db, const char *filename){
    FILE *file = fopen(filename, "rb");
    if(file){
        fread(&db->size, sizeof(int), 1, file);
        db->movies = (Movie *)realloc(db->movies, sizeof(Movie) * db->size);
        fread(db->movies, sizeof(Movie), db->size, file);
        fclose(file);
}
}

void addMovie(MovieDatabase *db, const char *title, const char *director, int year){
    if(db->size == db->capacity){
        db->capacity *= 2;
        db->movies = (Movie *)realloc(db->movies, sizeof(Movie) * db->capacity);
}
    strcpy(db->movies[db->size].title, title);
    strcpy(db->movies[db->size].director, director);
    db->movies[db->size].year = year;
    db->size++;

}
void editMovie(MovieDatabase *db, int index, const char *title, const char *director, int year){
    if(index >= 0 && index < db->size) {
         strcpy(db->movies[index].title, title);
        strcpy(db->movies[index].director, director);
        db->movies[index].year = year;           
}
}

void searchMovies(MovieDatabase *db, const char *keyword) {
    for(int i = 0; i < db->size; i++){
        if(strstr(db->movies[i].title, keyword) || strstr(db->movies[i].director, keyword)) {
            printf("Title: %s, Director: %s, Year: %d\n", db->movies[i].title, db->movies[i].director, db->movies[i].year);
}
}
}

void listMovies(MovieDatabase *db) {
    for(int i = 0; i < db->size; i++){
        printf("Title: %s, Director: %s, Year: %d\n", db->movies[i].title, db->movies[i].director, db->movies[i].year);  
}
}

void deleteMovie(MovieDatabase *db, int index) {
    if (index >= 0 && index < db->size) {
        for (int i = index; i < db->size - 1; i++) {
            db->movies[i] = db->movies[i + 1];
}
    db->size--;
}
}

int main(){
    MovieDatabase db;
    initializeDatabase(&db, 10);
    loadDatabase(&db, "movies.dat");

    int choice;
    char title[100], director[100];
    int year, index;

while(1){
    printf("1. Add Movie\n2. Edit Movie\n3. Delete Movie\n4. Search Movies\n5. List Movies\n6. Save and Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

switch(choice) {
    case 1:
    printf("Enter title: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Enter director: ");
    fgets(director, sizeof(director), stdin);
    director[strcspn(director, "\n")] = '\0';
    printf("Enter year: ");
    scanf("%d", &year);
    addMovie(&db, title, director, year);
    break;

    case 2:
    printf("Enter movie index to edit: ");
    scanf("%d", &index);
    if(index >= 0 && index < db.size){
        printf("Enter new title: ");
        getchar();
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        printf("Enter new director: ");
        fgets(director, sizeof(director), stdin);
        director[strcspn(director, "\n")] = '\0';
        printf("Enter new year: ");
        scanf("%d", &year);
        editMovie(&db, index, title, director, year);
    }
    break;
    
    case 3:
    printf("Enter movie index to delete: ");
    scanf("%d", &index);
    deleteMovie(&db, index);
    break;

    case 4:
    printf("Enter search keyword: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    searchMovies(&db, title);
    break;

    case 5:
    listMovies(&db);
    break;

    case 6: saveDatabase(&db, "movies.dat");
    freeDatabase(&db);
    return 0;
}
}
}