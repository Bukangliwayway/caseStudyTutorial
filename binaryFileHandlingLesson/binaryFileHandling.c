#include<stdlib.h>
#include<stdio.h>
#define filename "lesson3.dat"
struct team{
    char name[30];
    char role[30];
    int age;
};

int main(){
    FILE *file;
    struct team casestudy;
    file = fopen(filename, "wb");
    system("cls");
    printf("Name: ");
    scanf("\n");
    gets(casestudy.name);
    printf("Age: ");
    scanf("%d", &casestudy.age);
    printf("Role: ");
    scanf("\n");
    gets(casestudy.role);
    //Printing Struct datas to file
    fwrite(&casestudy, sizeof(struct team), 1, file);
    fclose(file);

    // system("cls");
    // casestudy = (struct team){0}; //Set the value of casestudy to none to prove that fread works
    // file = fopen(filename, "rb");
    // //Transferring datas from file to struct
    // fread(&casestudy, sizeof(struct team), 1, file);
    // printf("Name: %s\nAge: %d\nRole: %s\n", casestudy.name, casestudy.age, casestudy.role);
    // fclose(file);

    // file = fopen(filename, "ab");
    // system("cls");
    // printf("Name: ");
    // scanf("\n");
    // gets(casestudy.name);
    // printf("Age: ");
    // scanf("%d", &casestudy.age);
    // printf("Role: ");
    // scanf("\n");
    // gets(casestudy.role);
    // fwrite(&casestudy, sizeof(struct team), 1, file);
    // fclose(file);
    // // Reading Updated Datas from File
    // casestudy = (struct team){0}; //Set the value of casestudy to none to prove that fread works
    // file = fopen(filename, "rb");
    // fread(&casestudy, sizeof(struct team), 1, file);
    // printf("Name: %s\nAge: %d\nRole: %s\n", casestudy.name, casestudy.age, casestudy.role);
    // fclose(file);
    
    // file = fopen(filename, "rb+");
    // fread(&casestudy, sizeof(struct team), 1, file);
    // printf("Name: ");
    // scanf("\n");
    // gets(casestudy.name);
    // printf("Age: ");
    // scanf("%d", &casestudy.age);
    // printf("Role: ");
    // scanf("\n");
    // gets(casestudy.role);
    // fwrite(&casestudy, sizeof(struct team), 1, file);
    // fclose(file);    
    
    // file = fopen(filename, "ab+");
    // fread(&casestudy, sizeof(struct team), 1, file);
    // printf("Name: ");
    // scanf("\n");
    // gets(casestudy.name);
    // printf("Age: ");
    // scanf("%d", &casestudy.age);
    // printf("Role: ");
    // scanf("\n");
    // gets(casestudy.role);
    // fwrite(&casestudy, sizeof(struct team), 1, file);
    // fclose(file);    

    return 0;
}