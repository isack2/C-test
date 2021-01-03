#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void){

    char val_charmin = CHAR_MIN;
    char val_charmax = CHAR_MAX;
    char val_charover = CHAR_MAX + 1; //over flow
    unsigned char val_ucharmin = UCHAR_MAX + 1; //over flow
    unsigned char val_ucharmax = UCHAR_MAX;
    int val_intmin = INT_MIN;
    int val_intmax = INT_MAX;
    int val_intover = INT_MAX + 1;
    unsigned int val_uintmin = UINT_MAX + 1; //over flow
    unsigned int val_uintmax = UINT_MAX;
    float val_floatmin = FLT_MIN;
    float val_floatmax = FLT_MAX;
    float val_floatover = FLT_MAX + FLT_MAX;

    printf("char min : %d\n", val_charmin);
    printf("char max : %d\n", val_charmax);
    printf("char overflow : %d\n", val_charover); //over flow
    printf("unsigned char min : %u\n", val_ucharmin);
    printf("unsigned char max : %u\n", val_ucharmax);
    printf("int min : %d\n", val_intmin);
    printf("int max : %d\n", val_intmax);
    printf("int overflow : %d\n", val_intover); //over flow
    printf("unsigned int min : %u\n", val_uintmin);
    printf("unsigned int max : %u\n", val_uintmax);
    printf("float min : %.60f\n", val_floatmin);
    printf("float max : %.60f\n", val_floatmax);
    printf("float overflow : %.60f\n", val_floatover);
}