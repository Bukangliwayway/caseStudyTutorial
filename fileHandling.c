#include<stdlib.h>
#include<stdio.h>
#define filename "file.txt"
int main(){
    int num;
    char word[30];
    FILE *file;

    file = fopen(filename, "w");
    //Prints datas to the File
    fprintf(file, 19, "\tHelloWorld\n");
    fclose(file);
    
    // file = fopen(filename, "r");
    // // Terminate if file is non existing
    // if(file==NULL){
    //     printf("There is no such file!");
    //     return 0;
    // }
    // fscanf(file, "%d %s", &num, &word);
    // // Printing Scanned Datas from File to the Terminal
    // printf("%d\t%s\n", num, word);
    // fclose(file);

    // file = fopen(filename, "a");
    // printf("Enter a Number: ");
    // scanf("%d", &num);
    // printf("Enter Any Word: ");
    // scanf("\n");
    // gets(word);
    // // Printing/Appending Inputted Datas to the File
    // fprintf(file, "%d %s", &num, &word);
    // printf("%d\t%s\n", num, word);
    // fclose(file);

    return 0;
}