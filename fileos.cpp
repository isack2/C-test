#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

const int SIZE = 80;

int main(void){

    char arr[SIZE];
    char arrr[SIZE];

    using namespace std;
    string str;
    ofstream fileios; //파일 입, 출력 스트림 ifstream 은 파일 읽기만, iostream 은 파일 쓰기만 가능
    fileios.open("ios.txt"); // 입력을 redirection.txt으로 출력

    if(!fileios.is_open()){
        cout << "can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "input text data : ";
    cin.getline(arr, SIZE-1);
    fileios << arr;
    cout << endl;
    fileios.close();
}