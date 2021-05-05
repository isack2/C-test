#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIZE 100

int main(void){
    using namespace std;
    char *darr = new char;
    char **pdarr = new char*[SIZE];
    for(int i = 0 ; i < SIZE ; i++){
        pdarr[i] = new char;
    }
    char *dtox = new char;

    cin.getline(darr, 100);  
    cout << darr;
    dtox = strtok(darr, dtox);
    for(int i = 0 ; i < SIZE ; i++){
        cout << darr[i] << endl;
        dtox = strtok(darr, " ");
    }
    
    delete dtox;
    for(int j = 0 ; j > SIZE ; j++){
        delete [] pdarr[j];
    }
    delete [] pdarr;
    delete darr;
}
