#include<stdlib.h>
#include<stdio.h>
#define filename "binaryMembers.dat"
struct team{
    char name[30];
    char role[30];
    int age;
};

int main(){
    FILE *file;
    struct team member;
    int members;
    char repeat;
    system("cls");
    printf("How Many Members: ");
    scanf("%d",&members);
    file = fopen(filename, "wb");
    for(int i = 0; i < members; i++){
        system("cls");
        printf("Team Member #%d\n", i+1);
        printf("Name: ");
        scanf("\n");
        gets(member.name);
        printf("Age: ");
        scanf("%d", &member.age);
        printf("Role: ");
        scanf("\n");
        gets(member.role);
        // Printing Struct datas to file
        fwrite(&member, sizeof(struct team), 1, file);
    }
    fclose(file);

    system("cls");
    member = (struct team){0}; //Set the value of member to none to prove that fread works
    file = fopen(filename, "rb");
    //Transferring datas from file to struct
    printf("Viewing Files:\n\n");
    for(int i = 0; fread(&member, sizeof(struct team), 1, file) != (int)NULL; i++)
    printf("Team Member #%d\nName: %s\nAge: %d\nRole: %s\n\n", i+1, member.name, member.age, member.role);
    printf("Press Any Button to Continue...\nExcept the Power Button...\n");
    getch();
    fclose(file);
    do{
        system("cls");
        printf("How Many Members to Add: ");
        scanf("%d", &members);
        system("cls");
        file = fopen(filename, "ab");
        for(int i = 0; i < members; i++){
            system("cls");
            printf("Add Team Member #%d\n", i+1);
            printf("Name: ");
            scanf("\n");
            gets(member.name);
            printf("Age: ");
            scanf("%d", &member.age);
            printf("Role: ");
            scanf("\n");
            gets(member.role);
            // Printing Struct datas to file
            fwrite(&member, sizeof(struct team), 1, file);
        }
        fclose(file);
        //Reading the Updated Datas
        file = fopen(filename, "rb");
        system("cls");
        printf("Viewing Files:\n\n");
        for(int i = 0; fread(&member, sizeof(struct team), 1, file) != (int)NULL; i++)
        printf("Team Member #%d\nName: %s\nAge: %d\nRole: %s\n\n", i+1, member.name, member.age, member.role);
        printf("Press Any Button to Continue...");
        getch();
        fclose(file);
        system("cls");
        while(1){
            printf("Add Another Members? Y/N: ");
            scanf(" %c", &repeat);
            if(repeat == 'n' || repeat == 'y' || repeat == 'Y' || repeat == 'N') break;
            system("cls");
            printf("Invalid Input!\n\n");    
        }
    }while((repeat!='n' && repeat=='y') || (repeat!='N' && repeat=='Y'));
    return 0;
}