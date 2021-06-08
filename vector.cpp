#include<iostream>
using namespace std;

const void poew(const int, int exp = 2);
int main(){
    int x = 10;
    int y = 20;

    cout << x << " " << y << endl;
    swap(x,y);
    cout << x << " " << y << endl;

}

const void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}