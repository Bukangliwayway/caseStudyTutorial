#include<stdlib.h>
#include<stdio.h>
#define filename "lesson2.txt"
int main(){
    int num;
    char word[30];
    FILE *file;

    file = fopen(filename, "w");
    //Prints datas to the File
    fprintf(file,"1920 HelloWorld\n");
    fclose(file);
    printf("Click any button");
    getch();
    
    file = fopen(filename, "r");
    // Terminate if file is non existing
    if(file==NULL){
        printf("There is no such file!");
        return 0;
    }
    fscanf(file,"%d %s", &num, &word);
    // Printing Scanned Datas from File to the Terminal
    printf("%d\t%s\n", num, word);
    fclose(file);
    printf("Click any button");
    getch();

    file = fopen(filename, "a");
    printf("Enter a Number: ");
    scanf("%d", &num);
    printf("Enter Any Word: ");
    scanf("\n");
    gets(word);
    // Printing/Appending Inputted Datas to the File
    fprintf(file, "\n%d %s", num, word);
    fclose(file);

    return 0;
}