#include<iostream>
#include<cstring>
#define SIZE 100

int charsize(char *);
int wordsize(char *);

int main(void){
    using namespace std;

    char *temp = new char;
    char *strarr = new char;
    int *numarr = new int;
    int csize = 0;
    int wsize = 0;
    
    cin.getline(temp, SIZE);
    csize = charsize(temp);
    wsize = wordsize(temp);

    char **tempbucket = new char*[wsize];
    for(int i = 0 ; i < wsize ; i++){
        tempbucket[i] = new char;
    }

    char *tok = new char;
    tok = strtok(temp, " ");

    for(int i = 0 ; i < wsize ; i++){
        if(tok != NULL){
            tempbucket[i] = tok;
            tok = strtok(NULL, " ");
        }
    }

    for(int i = 0 ; i < wsize ; i++){
        cout << "tempbuck[" << i << "]: " << tempbucket[i] << endl;
    }

    delete tok;
    for(int j = 0 ; j < wsize + 1; j++){
        delete [] tempbucket[j];
    }
    delete [] tempbucket;
    delete temp;
    delete strarr;
    delete numarr;
}

int charsize(char *arr){
    int i = 0;
    int csize = 0;

    while(arr[i] != '\0'){
        if(arr[i] == ' '){
            i++;
        }
        csize++;
        i++;
    }
    return csize;
}

int wordsize(char *arr){
    int wsize = 0;
    char *tox = new char;
    char *temparr = new char;
    char **bucket = new char*[SIZE];
    for(int i = 0 ; i < SIZE ; i++){
        bucket[i] = new char;
    }

    strcpy(temparr, arr);
    tox = strtok(temparr, " ");

    for(int i = 0 ; i < SIZE ; i++){
        if(tox != NULL){
            wsize++;
            tox = strtok(NULL, " ");
        }
    }
    delete tox;
    delete temparr;
    return wsize;
}