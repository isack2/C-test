#include<stdio.h>

int multiple(int);
int unmultiple(int);

int main(void){
    int size_char = sizeof(char);
    int size_unchar = sizeof(unsigned char);
    int size_int = sizeof(int);
    int size_unint = sizeof(unsigned int);
    int size_float = sizeof(float);

    char val_char = multiple(size_char);
    unsigned char val_unchar = unmultiple(size_unchar);
    int val_int = multiple(size_int);
    unsigned int val_unint = unmultiple(size_unint);
    float val_float = multiple(size_float);

    printf("size of char : %d\n", size_char);
    printf("size of unchar : %d\n", size_unchar);
    printf("size of int : %d\n", size_int);
    printf("size of unint : %d\n", size_unint);

    printf("range of char : %d ~ %d\n", -val_char, val_char);
    printf("range of unchar : %u ~ %u\n", 0, val_unchar);
    printf("range of int : %d ~ %d\n", -val_int, val_int);
    printf("range of unint : %u ~ %u\n", 0,val_unint);

    printf("overflow char : %d\n", val_char+1);
    printf("overflow unchar : %d\n", val_unchar+1);
    printf("overflow int : %d\n", val_int+1);
    printf("overflow unint : %d\n", val_unint+1);
 
}

int multiple(int size){
    int value = 2;
    for(int i = 1 ; i < (8 * size - 1); i++){
        value = (value * 2);
    }

    return value - 1;
}

int unmultiple(int size){
    int value = 2;
    for(int i = 1 ; i < (8 * size) ; i++){
        value = (value * 2);
    }

    return value - 1;
}