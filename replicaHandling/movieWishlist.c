#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define replicaname "replica.dat"
#define filename "movieList.dat"

// Max of 25 Records only since I use the alphabets here. (including the Exit Choice)
// Also 25 movies in a list is damn too much already okay?? Just delete some instead.

struct list{
    char movieName[30];
    char director[30];
    int releaseDate;
    float ratings;
};

FILE *original, *replica;
struct list movie;
int movieCount;
char select;
void addMovies();
void viewMovies();
void editMovie();
void removeMovie();
void addProcess();

int main(){
    system("cls");
    while(1){
        while(1){
            original = fopen(filename, "rb");
            printf("Main Menu:\n");
            printf("A. Add Movies\nB. View Movies\nC. Edit Movies\nD. Remove Movies\nE. Exit\n");
            printf("Select Process: ");
            scanf(" %c", &select);
            if(original != NULL){
                fseek(original, 0, SEEK_END);
                if(ftell(original)!=0) break;
                if(ftell(original)==0 && (select == 'A' || select == 'E'))break;
            }
            system("cls");
            printf("There is no recorded movie.\nAdd movies first\n\n");
            fclose(original);
        }
        system("cls");
        switch(select){
            case 'A':
                addMovies();
                break;
            case 'B':
                viewMovies();
                break;
            case 'C':
                editMovie();
                break;
            case 'D':
                removeMovie();
                break;
            case 'E':
                printf("Process Terminated Successfully...");
                return 0;
            default:
                system("cls");
                printf("Invalid Input!\n\n");
        }
        if(select >= 'A' && select <= 'D') system("cls");
    }
}

void addMovies(){
    int movies;
    original = fopen(filename, "ab");
    while(1){
        printf("Add Movies:\nA. Add a Movie\nB. Add Multiple Movies\nSelect process: ");
        scanf(" %c", &select);
        if(select=='A' || select=='B') break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    system("cls");
    if(select=='A'){
        printf("Add Movie\n\n");
        addProcess();
        fwrite(&movie, sizeof(struct list), 1, original);
    }else{
        while(1){
            printf("How Many Movies: ");
            scanf("%d", &movies);
            if(movies > 0 && movies < 100) break;
            system("cls");
            printf("Either it's too much or too less\n\n");
        }
        for(int i = 0; i < movies; i++){
            system("cls"); 
            printf("Movie#%d\n\n", i+1);
            addProcess();
            fwrite(&movie, sizeof(struct list), 1, original);
        }
    }
    fclose(original);
}

void addProcess(){
    printf("Movie Name: ");
    scanf("\n");
    gets(movie.movieName);
    printf("Movie Director: ");
    scanf("\n");
    gets(movie.director);
    printf("Release Date: ");
    scanf("%d", &movie.releaseDate);
    printf("Ratings: ");
    scanf("%f", &movie.ratings);
}

void viewMovies(){
    original = fopen(filename, "rb");
    while(1){
        movieCount = 0;
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            printf(" %c. %s\t%d\n",'A'+i, movie.movieName, movie.releaseDate);
            movieCount++;
        }
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fseek(original, 0, SEEK_SET);
        printf("Select Movies: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    fclose(original);
    system("cls");
    original = fopen(filename, "rb");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i != select-'A') continue;
        printf("Movie Name: %s\nMovie Director: %s\nDate Realease: %d\nRatings: %0.1f\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
        printf("\nPress Any key to quit...");
        getch();
        break;
    }
    fclose(original);
}

void editMovie(){
    original = fopen(filename, "rb");
    while(1){
        movieCount = 0;
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            printf(" %c. %s\n",'A'+i, movie.movieName);
            movieCount++;
        }
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fseek(original, 0, SEEK_SET);
        printf("Select Movies: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    fclose(original);
    if(select == 'A'+ movieCount) return;
    movieCount = (int)select; // aaaaaaaa I don't wanna use and waste another variable just to save this line okay?!
    system("cls");
    while(1){   
        original = fopen(filename, "rb");
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            if(i != movieCount-'A') continue;
            printf("A. Movie Name: %s\nB. Movie Director: %s\nC. Date Release: %d\nD. Ratings: %0.1f\nE. Exit Process\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
            break;
        }
        printf("\nChoose Data to Edit: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'E') break;
        fclose(original);
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    system("cls");
    original = fopen(filename, "rb");
    replica = fopen(replicaname, "wb");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i == movieCount-'A'){
            switch(select){
                case 'A':
                    printf("Current Data:\nMovie Name: %s\n", movie.movieName);
                    printf("Movie Name: ");
                    scanf("\n");
                    gets(movie.movieName);
                    break;
                case 'B':
                    printf("Current Data:\nMovie Director: %s\n", movie.director);
                    printf("Movie Director: ");
                    scanf("\n");
                    gets(movie.director);
                    break;
                case 'C':
                    printf("Current Data:\nRelease Date: %d\n", movie.releaseDate);
                    printf("Release Date: ");
                    scanf("%d", &movie.releaseDate);
                    break;
                case 'D':
                    printf("Current Data:\nRatings: %0.1f\n", movie.ratings);
                    printf("Ratings: ");
                    scanf("%f", &movie.ratings); 
                    break;
                case 'E':
                    fclose(original);
                    fclose(replica);
                    return;
            }
            fwrite(&movie, sizeof(struct list), 1, replica);
            continue;
        }
        fwrite(&movie, sizeof(struct list), 1, replica);
    }
    fclose(replica);
    fclose(original);
    //Deletes the existing outdated file.dat
    system("cls");
    if(remove(filename)){
        perror("File Deletion Failed!\nSuggestion: Open the Editor in Admin\n");
        getch();
    } 
    //Deletes the existing outdated file.dat
    if(rename(replicaname, filename)){
        perror("\nFile Rename Failed!\n");
        getch();
    } 
    system("cls");
    original = fopen(filename, "rb");
    printf("Here are the updated Datas: \n\n");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i != movieCount-'A') continue;
        printf("A. Movie Name: %s\nB. Movie Director: %s\nC. Date Release: %d\nD. Ratings: %0.1f\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
        printf("Press any key to quit...");
        getch();
        break;
    }
    fclose(original);
}

void removeMovie(){
    original = fopen(filename, "rb");
    while(1){
        movieCount = 0;
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            printf(" %c. %s\n",'A'+i, movie.movieName);
            movieCount++;
        }
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fseek(original, 0, SEEK_SET);
        printf("Select Movies to Remove: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    fclose(original);
    if(select == 'A'+ movieCount) return;
    system("cls");
    original = fopen(filename, "rb");
    replica = fopen(replicaname, "wb");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i == select-'A') continue;
        fwrite(&movie, sizeof(struct list),1,replica);
    }
    fclose(replica);
    fclose(original);
    //Deletes the existing outdated file.dat
    system("cls");
    if(remove(filename)){
        perror("File Deletion Failed!\nSuggestion: Open the Editor in Admin\n");
        getch();
    } 
    //Deletes the existing outdated file.dat
    if(rename(replicaname, filename)){
        perror("\nFile Rename Failed!\n");
        getch();
    } 
    system("cls");
    original = fopen(filename, "rb");
    printf("Here is the updated record: \n\n");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++)
        printf(" %c. %s\t%d\n", 'A'+i, movie.movieName, movie.releaseDate);
    printf("Press any key to quit...");
    getch();
    fclose(original);
}