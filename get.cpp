#include<iostream>
#include<fstream>

const int size = 80;

int main(void){

    using namespace std;
    ifstream textitle;
    char arr[size];
    cin.getline(arr, size-1);
    textitle.open("test.txt");
    textitle >> arr;
}