#include<iostream>
#include<cstdlib>

typedef struct Str
{
    int data;
}str_arr;

str_arr a1, a2, a3;
str_arr *arr[3] = {&a1, &a2, &a3};
str_arr **ptr = arr;

int main(void){
    using namespace std;
    (*arr)->data = 12;
    arr[1]->data = 13;
    (*arr + 2)->data = 14;
    cout << "arr[0] adress : " << (ptr) << endl; // ptr = &arr = arr[0] adress
    cout << "arr[0] adress : " << &arr[0] << endl;
    cout << "arr[0] adress : " << (arr) << endl; // arr[0] adress
    cout << "arr[1] adress : " << (ptr + 1) << endl;
    cout << "arr[1] adress : " << &arr[1] << endl;
    cout << "arr[1] adress : " << (arr + 1) << endl;
    cout << "arr[2] adress : " << (ptr + 2) << endl;
    cout << "arr[2] adress : " << &arr[2] << endl;
    cout << "arr[2] adress : " << (arr + 2) << endl;
    cout << "a1 adress : " << (arr + 2) << endl;
    cout << "a1 adress : " << *(ptr) << endl; // *ptr = arr = a1 adress
    cout << "a1 adress : " << (arr[0]) << endl; // arr[0] = a1 adress
    cout << "a1 adress : " << &a1 << endl; //a1 adress
    cout << "a2 adress : " << *(ptr + 1) << endl;
    cout << "a2 adress : " << &a2 << endl;
    cout << "a3 adress : " << *(ptr + 2) << endl;
    cout << "a3 adress : " << &a3 << endl;
    cout << "a1[0] value : " << (*arr)->data << endl;
    cout << "a1[0] value : " << a1.data << endl;
    cout << "a1[0] value : " << (*ptr)->data << endl;
    cout << "a1[0] value : " << (**ptr).data << endl;
    cout << "a1[1] value : " << (*arr + 1)->data << endl;
    cout << "a1[1] value : " << a2.data << endl;
    cout << "a1[1] value : " << (*ptr + 1)->data << endl;
    cout << "a1[2] value : " << (**(ptr + 1)).data << endl;
    cout << "a1[2] value : " << (*arr + 2)->data << endl;
    cout << "a1[2] value : " << a3.data << endl;
    cout << "a1[2] value : " << (*ptr + 2)->data << endl;
    cout << "a1[2] value : " << (**(ptr + 2)).data << endl;
}