#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIZE 100

int main(void){
    using namespace std;

    char *srr = new char;
    int size = 0;

    cout << "input: ";
    cin.getline(srr, SIZE);
    size = strlen(srr);
    cout << "size: " << size << endl;

    char **sArr = new char*[10];
    for(int i = 0 ; i < 10 ; i++){
        sArr[i] = new char[SIZE];
    }
    int i = 0;

    char *ptr = strtok(srr, " ");

    while(ptr != NULL){
        sArr[i] = ptr;
        i++;
        ptr = strtok(NULL, " ");    
    }

    for(int i = 0 ; i < 10 ; i++){
        if(sArr[i] != NULL){
            cout << sArr[i];
        }
    }

    cout << endl;

    char *asmble = new char;

    for(int i = 0 ; i < 10 ; i++){
        strcat(asmble, sArr[i]);
        strcat(asmble, " ");
    }

    cout << asmble << endl;

    for(int i = 0 ; i < 10 ; i++){
        delete [] sArr[i];
    }

    delete [] sArr;
    delete srr;
    delete asmble;
}