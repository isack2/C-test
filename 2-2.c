#include<stdio.h>
#include<time.h>
#define year 365
#define january 31
#define fabruary 28
#define march 31
#define april 30
#define may 31
#define june 30
#define july 31
#define august 31
#define setember 30
#define october 31
#define november 30
#define december 31

time_t t = time(NULL);
struct tm = *localtime(&t);

struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_min;
    int tm_day;
    int tm_month;
    int tm_year;
    int tm_mday;
}tm;

int main(void){

    int y = 1990;
    int m = 8;
    int d = 12;
    printf("%d, %d, %d", tm.tm_year, tm.tm_month, tm.tm_day);
}