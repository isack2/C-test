#include<iostream>
using namespace std;

void printout(int);

int main(void){
    printout(5243);

}

void printout(int n){
    if(n >= 10){
        printout(n / 10);
    }
    cout << n % 10 << endl;
}