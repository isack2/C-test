#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int size = 80;

int main(void){

    char arr[size];
    FILE *fileopen = NULL;
    fileopen = fopen("redirection.txt", "r");

    if(fileopen == NULL){
        puts("Can't open file");
        return EXIT_FAILURE;
    }
    else{
        puts("Open File");
        fgets(arr, sizeof(arr), fileopen);
        printf("%s\n", arr);
        return EXIT_SUCCESS;
    }
    fclose(fileopen);
}