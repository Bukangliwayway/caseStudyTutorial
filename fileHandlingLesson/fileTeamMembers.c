#include<stdlib.h>
#include<stdio.h>
#define filename "projectMembers.txt"
int main(){
    system("cls");
    int members, age, addMembers;
    char name[30], role[30];
    FILE *file;

    file = fopen(filename, "w");
    //Prints datas to the File
    printf("How Many Members to Input: ");
    scanf("%d", &members);

    for(int i = 0; i < members; i++){
        system("cls");
        printf("Team Member#%d\n", i+1);
        printf("Name: ");
        scanf("\n");
        gets(name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Role: ");
        scanf("\n");
        gets(role);
        fprintf(file, "%s\t%d\t%s\n", name,age,role);
    }
    printf("Press any button\n");
    getch();
    fclose(file);
    system("cls");
    file = fopen(filename, "r");
    // Terminate if file is non existing
    if(file==NULL){
        printf("There is no such file directory!");
        return 0;
    }
    for(int i = 0; i < members; i++){
        fscanf(file, "%s %d %s", &name, &age, &role);
        printf("Team Member#%d\nName: %s\nAge: %d\nRole: %s\n\n", i+1, name, age, role);
    }
    fclose(file);
    getch();
    system("cls");
    file = fopen(filename, "a");
    printf("How Many Members to Add: ");
    scanf("%d", &addMembers);
    for(int i = 0; i < addMembers; i++){
        system("cls");
        printf("Team Member#%d\n", i+1);
        printf("Name: ");
        scanf("\n");
        gets(name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Role: ");
        scanf("\n");
        gets(role);
        fprintf(file, "%s\t%d\t%s\n", name,age,role);
    }
    fclose(file);
    printf("\npress any button to proceed");
    getch();
    file = fopen(filename, "r");
    // Terminate if file is non existing
    if(file==NULL){
        printf("There is no such file directory!");
        return 0;
    }
    system("cls");
    for(int i = 0; i < 5; i++){
        fscanf(file, "%s %d %s", &name, &age, &role);
        printf("Team Member#%d\nName: %s\nAge: %d\nRole: %s\n\n", i+1, name, age, role);
    }
    fclose(file);
    return 0;
}