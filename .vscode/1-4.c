#include<stdio.h>

void jolly(void){
    printf("jolly good ");
}

void deny(void){
    printf("which nobody can deny!");
}

int main(void){
    for(int i = 0 ; i < 3 ; i++){
        printf("for he's a ");
        jolly();
        printf("fellow!\n");
    }
    deny();
    }