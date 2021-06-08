#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef struct _Node{
    int data;
    _Node *next;
}Node;

typedef struct _Stack{
    _Node *top;
}Stack;

int main(void){
    string s;
    char *bucket = new char;
    int size;
    int bucketcount = 0;

    getline(cin, s);
    strcpy(bucket, s.c_str());
    size = strlen(bucket);

    char **tokbucket = new char*[size];
    for(int i = 0 ; i < size ; i++){
        tokbucket[i] = new char;
    }

    char *tok = new char;
    tok = strtok(bucket, " ");
    int index = 0;

    while(tok != NULL){
        strcpy(tokbucket[index++], tok);
        bucketcount++;
        tok = strtok(NULL, " ");
    }

    for(int i = 0 ; i < bucketcount ; i++){
        cout << tokbucket[i] << endl;
    }



    for(int i = 0 ; i < size ; i++){
        delete tokbucket[i];
    }
    delete [] tokbucket;
    delete bucket;
    delete tok;
}


    