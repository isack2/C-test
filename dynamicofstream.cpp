#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>

int main(void){

    using namespace std;
    int size;
    //char *ptr = new char; //char 동적할당
    char *ptarr = new char[size];//char 배열 동적할당

    cout << "input : ";
    cin.getline(ptarr, size);
    cout << ptarr << endl;
    size = strlen(ptarr);
    
    ofstream dyofstream;
    dyofstream.open("dynamicif.txt");

    if(!dyofstream.is_open()){
        cout << "fail open file!" << endl;
        exit(EXIT_FAILURE);
    }
    dyofstream << ptarr;
    dyofstream.close();
    //delete ptr; //char 동적할당 삭제
    delete [] ptarr;//char 배열 동적할당 삭제
}

