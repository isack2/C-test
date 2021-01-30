#include<iostream>
#include<cstring>

int main(void){

    using namespace std;
    char space[20];
    string str1;
    cout << " input is : ";
    cin.getline(space, 20); // cin.getline 함수는 화이트 스페이스 포함하여 문자열 끝까지 읽는다.
    cout << "cin.getline output is : " << space << endl << "input is : ";
    getline(cin, str1); // getline 함수 역시 화이트 스페이스 포함하여 문자열 끝까지 읽는다.
    cout << "getline output is : " << str1 << endl;

    return 0;
}