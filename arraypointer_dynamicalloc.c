#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    int size;
    char temparr[size];
    char (*arr)[size] = (char(*)[size])malloc(sizeof(char));
    int i = 0;

    while(getchar() != 'q'){
        char temp[10];
        printf("문자를 입력해 주세요\n");
        temp[10] = getchar();
        strcpy(arr, temp);
        i++;
    }

    while(arr[i] != '\0'){
        printf("%c", arr[i]);
    }

}