#include<iostream>
using namespace std;

typedef struct _Test{
    int id;
    char data[20];
}Test;
int returnid(Test *);

int main(void){
    Test *list = new Test;
    list[0].id = 1;
    list[1].id = 2;
    (list + 2)->id = 3;

    cout << list[0].id << endl << list[1].id << (list + 2)->id << endl;

}

int returnid(Test *dat){
    
}