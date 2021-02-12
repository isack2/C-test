#include<iostream>
#include<string>
#include<fstream>

const int SIZE = 80;

int main(void){

    using namespace std;
    string temp;
    ifstream fileios;

    cout << "reading file..." << endl << endl;
    fileios.open("ios.txt");

    if(!fileios.is_open()){
        cout << "can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    getline(fileios, temp);
    cout << temp << endl;
    fileios.close();
}