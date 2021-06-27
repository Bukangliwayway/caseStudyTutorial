#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//Defining Struct Metadata
struct metadata{
    char songName[15];
    char genre[15];
    int length; // in seconds
    float ratings;
};

int main(){
    //Declaring Struct
    struct metadata song;
    // Assigning Struct
    strcpy(song.songName, "Blackbird");
    strcpy(song.genre, "Pop");
    song.length = 120; 
    song.ratings = 4.5;
    // Printing Struct
    printf("Name: %s\nGenre: %s\nLength: %d seconds\nRatings: %0.1f", song.songName, song.genre, song.length, song.ratings);
    
    // // Assing Struct using Input
    // printf("Name: ");
    // scanf("\n");
    // gets(song.songName);
    // printf("Genre: ");
    // gets(song.genre);
    // printf("Length: ");
    // scanf("%d", &song.length);
    // printf("Ratings: ");
    // scanf("%f",&song.ratings);
    // //Printing Struct
    // printf("Name: %s\nGenre: %s\nLength: %d seconds\nRatings: %0.1f", song.songName, song.genre, song.length, song.ratings);


    return 0;
}