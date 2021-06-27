#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//Defining Struct Metadata
struct metadata{
    char songName[30];
    char genre[15];
    char band[15];
    int length; // in seconds
    float ratings;
};

int main(){
    int number;
    system("cls");
    printf("How Many Songs to Add: ");
    scanf("%d", &number);
    //Declaring Struct
    struct metadata song[number];
    for(int i = 0; i < number; i++){     
        // Assing Struct using Input
        system("cls");
        printf("Song #%d\n", i+1);
        printf("Name: ");
        scanf("\n");
        gets(song[i].songName);
        printf("Band: ");
        scanf("\n");
        gets(song[i].band);
        printf("Genre: ");
        scanf("\n");
        gets(song[i].genre);
        printf("Length: ");
        scanf("%d", &song[i].length);
        printf("Ratings: ");
        scanf("%f",&song[i].ratings);
    }
    system("cls");
    for(int i = 0; i < number; i++)
    printf("Song#%d\nName: %s\nBand: %s\nGenre: %s\nLength: %d seconds\nRatings: %0.1f\n\n", i+1, song[i].songName, song[i].band, song[i].genre, song[i].length, song[i].ratings);
    return 0;
}