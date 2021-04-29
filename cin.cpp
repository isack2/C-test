#include<iostream>
#include<cstring>
#include<string>
#define SIZE 100

void seperate(char *, char *);

int main(void){
    using namespace std;
    char input[SIZE] ={0};
    char temp[SIZE] = {0};
    int count = 0;
    int arrcount = 0;

    cin.getline(input, SIZE);
    cout << input << endl;
    seperate(input, temp);
}

void seperate(char *arr, char *tarr){
    int count = 0;
    int i = 0;


    while(count < SIZE){
        while(arr[count] != ' '){
            tarr[i] = arr[count];
            count++;
            i++;
            }
        std::cout << tarr << std::endl;
        std ::cout << count << std::endl;
        tarr = {0};
        while(arr[count] == ' '){
            count++;
        }
        std::cout << count << std::endl;
        i = 0;
        std::cout << i << std::endl;
    }
}