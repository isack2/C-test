#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>

int main(void){

    using namespace std;
    int size;
    int temp;
    int i = 0;
    int *ptarr = new int;

    ifstream dyifstream;
    dyifstream.open("dynamicif.txt");
    if(!dyifstream.is_open()){
        cout << "fail open file!";
        exit(EXIT_FAILURE);
    }
    while(dyifstream.good()){
        if((i % 4) == 0){
            cout << endl;
            i++;
        }
        else{
            dyifstream >> temp;
            cout << " " << temp;
            i++;
        }
    }

    delete ptarr;
    dyifstream.close();
}