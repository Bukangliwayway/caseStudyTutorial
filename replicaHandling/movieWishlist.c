#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define replicaname "replica.dat"
#define filename "movieWishlist.dat"

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
            if(original == NULL && (select <= 'A' || select >= 'E')) break;
            if(original != NULL){
                fseek(original, 0, SEEK_END);
                if(ftell(original)!=0) break;
                if(ftell(original)==0 && (select <= 'A' || select >= 'E'))break;
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
        system("cls");
    }
}

void addMovies(){
    int movies;
    movieCount = 0;
    original = fopen(filename, "rb");
    while(fread(&movie, sizeof(struct list), 1, original)!= (int)NULL) movieCount++;    
    system("cls");
    if(movieCount >= 25){
        printf("Records Exceeded. Delete some Files First!\n\n"); getch();
        return;
    } 
    fclose(original);

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
        original = fopen(filename, "ab");
        fwrite(&movie, sizeof(struct list), 1, original);
        fclose(original);
    }else{
        while(1){
            printf("Input 0 for exit!\nHow Many Movies: ");
            scanf("%d", &movies);
            if(movies >= 0 && movies <= (25-movieCount)) break;
            system("cls");
            printf("Either it's too much or too less\n\n");
        }
        original = fopen(filename, "ab");
        for(int i = 0; i < movies; i++){
            system("cls"); 
            printf("Movie#%d\n\n", i+1);
            addProcess();
            fwrite(&movie, sizeof(struct list), 1, original);
        }
        fclose(original);
    }
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
    while(1){
        original = fopen(filename, "rb");
        movieCount = 0;
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            printf(" %c. %s\t%d\n",'A'+i, movie.movieName, movie.releaseDate);
            movieCount++;
        }
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fclose(original);
        printf("Select Movies: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    system("cls");
    original = fopen(filename, "rb");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i != select-'A') continue;
        printf("Movie Name: %s\nMovie Director: %s\nDate Release: %d\nRatings: %0.1f\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
        printf("\nPress Any key to quit...");
        getch();
        break;
    }
    system("cls");
    fclose(original);
}

void editMovie(){
    while(1){
        original = fopen(filename, "rb");
        movieCount = 0;
        //Process 1: Select Movies
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++, movieCount++)
            printf(" %c. %s\n",'A'+i, movie.movieName);
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fclose(original);
        printf("Select Movies: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    if(select == 'A'+ movieCount) return;
    movieCount = (int)select; // aaaaaaaa I don't wanna use and waste another variable just to save this line okay?!
    system("cls");
    //Process 2: Select Datas

    while(1){   
        original = fopen(filename, "rb");
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
            if(i == movieCount-'A'){
                printf("A. Movie Name: %s\nB. Movie Director: %s\nC. Date Release: %d\nD. Ratings: %0.1f\nE. Exit Process\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
                break;
            }
        }
        fclose(original);
        printf("\nChoose Data to Edit: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'E') break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    system("cls");
    //Process 3: Input the Update
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
    //Rename the Replica to Original
    if(rename(replicaname, filename)){
        system("cls");
        perror("File Rename Failed!\nCopying the content of Replica to the Original Instead...\n");
        getch();
        original = fopen(filename, "wb");
        replica = fopen(replicaname, "rb");
        for(int i = 0; fread(&movie, sizeof(struct list), 1, replica) != (int)NULL; i++)
            fwrite(&movie, sizeof(struct list), 1, original);
        fclose(replica);
        fclose(original);
    } 
    system("cls");
    //Process 4: Show Updated Datas
    original = fopen(filename, "rb");
    printf("Here are the updated Datas: \n\n");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i == movieCount-'A'){
            printf("A. Movie Name: %s\nB. Movie Director: %s\nC. Date Release: %d\nD. Ratings: %0.1f\n", movie.movieName, movie.director, movie.releaseDate, movie.ratings);
            printf("Press any key to quit...");
            getch();
            break;
        }
    }
    fclose(original);
}

void removeMovie(){
    //Process 1: Choose Movie
    while(1){
        original = fopen(filename, "rb");
        movieCount = 0;
        //Printing Movies Name
        for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++, movieCount++)
            printf(" %c. %s\n",'A'+i, movie.movieName);
        //Print Exit process with respect to the number of the available files
        printf(" %c. Exit Process\n\n", 'A'+movieCount);
        fclose(original);
        printf("Select Movies to Remove: ");
        scanf(" %c", &select);
        if(select >= 'A' && select <= 'A'+ movieCount) break;
        system("cls");
        printf("Invalid Choice!\n\n");
    }
    if(select == 'A'+ movieCount) return;
    system("cls");
    replica = fopen(replicaname, "wb");
    original = fopen(filename, "rb");
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++){
        if(i == select-'A') continue;
        fwrite(&movie, sizeof(struct list), 1, replica);
    }
    fclose(original);
    fclose(replica);
    //Deletes the existing outdated file.dat
    if(remove(filename)){
        system("cls");
        perror("File Deletion Failed!\nSuggestion: Open the Editor in Admin\n");
        getch();
    } 
    //Rename the Replica to Original
    if(rename(replicaname, filename)){
        system("cls");
        perror("File Rename Failed!\nCopying the content of Replica to the Original Instead...\n");
        getch();
        original = fopen(filename, "wb");
        replica = fopen(replicaname, "rb");
        //Copy Every Lines in Replica to Original
        for(int i = 0; fread(&movie, sizeof(struct list), 1, replica) != (int)NULL; i++)
            fwrite(&movie, sizeof(struct list), 1, original);
        fclose(replica);
        fclose(original);
    }
    system("cls");
    //Process 2: Show The Updated Datas
    original = fopen(filename, "rb");
    printf("Here's the updated record: \n");
    //Print Every Line in Original File
    for(int i = 0; fread(&movie, sizeof(struct list), 1, original) != (int)NULL; i++)
        printf(" %c. %s\t%d\n", 'A'+i, movie.movieName, movie.releaseDate);
    printf("Press any key to quit...");
    getch();
    fclose(original);
}