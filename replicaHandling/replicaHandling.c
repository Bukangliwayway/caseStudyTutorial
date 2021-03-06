#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define anykey printf("\nPress Anykey to proceed...\n"); getch()
#define replicaname "replica.dat"
#define filename "lesson4.dat"

struct team{
    char name[30];
    char id[20];
};

int main(){
    FILE *original, *replica;
    struct team members;
    int delete;
    //Code for inputting 2 records inside the list
    system("cls");
    anykey;
    original = fopen(filename, "wb");
    strcpy(members.name, "Maria Juana");
    strcpy(members.id, "18001704500");
    fwrite(&members, sizeof(struct team), 1, original);
    strcpy(members.name, "Yoshi Taro");
    strcpy(members.id, "18007237500");
    fwrite(&members, sizeof(struct team), 1, original);
    anykey;
    fclose(original);
    anykey;
    //To Read the original
    system("cls");
    original = fopen(filename, "rb");
    for(int i = 0; fread(&members, sizeof(struct team), 1, original) != (int)NULL; i++)
        printf("%d. %s\t%s\n", i+1, members.name, members.id);
    fclose(original);

    //IO for line to delete
    printf("Choose Record to Delete: ");
    scanf("%d", &delete);

    replica = fopen(replicaname, "wb");
    anykey;
    original = fopen(filename, "rb");
    // This copy the content from original.dat to replica.dat except the chosen line to delete
    for(int i = 0; fread(&members, sizeof(struct team), 1, original) != (int)NULL; i++){
        if(i==delete-1) continue;
        fwrite(&members, sizeof(struct team), 1, replica);
    }
    fclose(original);
    fclose(replica);
    anykey;

    remove(filename); //Deletes the existing outdated original.dat
    anykey;
    rename(replicaname, filename); // rename the replica original to original.dat
    anykey;
    system("cls");
    //To Read the original
    original = fopen(filename, "rb");
    for(int i = 0; fread(&members, sizeof(struct team), 1, original) != (int)NULL; i++)
        printf("%d. %s\t%s", i+1, members.name, members.id);
    fclose(original);
    
    return 0;
}   