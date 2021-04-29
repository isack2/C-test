#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#define SIZE 1000

typedef struct _Node{

    char data[SIZE];
    char *next;

}Node;

typedef struct _Struct{

    Node *top;

}Struck;

void push(Node *, char *);
void decoll(char *, char *);

int main(void){

    using namespace std;
    char array[SIZE] = {0};
    char temp[SIZE] = {0};

    cout << "input: ";
    cin.getline(temp, SIZE - 1);
    cout << temp << endl;
    decoll(temp, array);
    cout << array << endl;
    decoll(temp, array);
    cout << array << endl;
    decoll(temp, array);
    cout << array << endl;
    decoll(temp, array);
    cout << array << endl;
}

void push(Node *node, char *dat){

}

void decoll(char *tem, char *arr){
    int i = 0;
    int j = 0;
    while(tem[i] != NULL){
        if(tem[i] != ' '){
            arr[i] = tem[i];
            i++;
        }
        else{
            arr[i] = NULL;
            while(tem[i] == ' ' && i < SIZE){
                i++;
            }
            if(i < SIZE){
                for(int j = 0 ; j < SIZE - i - 1 ; j++){
                    tem[j] = tem[j+i];
                    }
                    for(j = SIZE - i - 1 ; j < SIZE ; j++){
                        tem[j] = '\0';
                        }
            }
            else{
                tem[SIZE] = NULL;
                break;
            }
        }
    }
    arr[SIZE] = {0};
}