#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;

}goes;


goes *now;
goes *birth;
goes *mybirth;

int main(void){

    int mon[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gyear = 0, gday = 0, gsec = 0;
    time_t sec;

    now = malloc(sizeof(goes));
    now->second = time(&sec);
    now->minute = now->second/60;
    now->hour = now->minute/60;
    now->day = now->hour/24;
    now->year = now->day/365;

    birth = malloc(sizeof(goes));
    birth->year = 20;
    birth->month = 8;
    birth->day = 12;

    for(int i=0 ; i<birth->month ; i++){
        gday = gday + mon[i];
        }
        
        gday = gday + birth->day + birth->year*365;
        gsec = gday*24*60*60;
         
        mybirth = malloc(sizeof(goes));
        mybirth->second = now->second - gsec;
        mybirth->minute = mybirth->second/60;
        mybirth->hour = mybirth->minute/60;
        mybirth->day = mybirth->hour/24;
        mybirth->year = mybirth->day/365;

    printf("since(sec) : %d\n", now->second);
    printf("since(min): %d\n", now->minute);
    printf("since(hour): %d\n", now->hour);
    printf("since(day) : %d\n", now->day);
    printf("since(year) : %d\n", now->year);

    printf("my birth(sec) : %d\n", mybirth->second);
    printf("my birth(min): %d\n", mybirth->minute);
    printf("my birth(hour): %d\n", mybirth->hour);
    printf("my birth(day) : %d\n", mybirth->day);
    printf("my birth(year) : %d\n", mybirth->year);
    
    free(now);
    free(birth);
    free(mybirth);
}