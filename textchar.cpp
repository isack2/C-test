#include<iostream>
#include<cstring>

int main(void){

    using namespace std;

    char cinarr[20]; // 단일문자 상수 'char' 입력가능
    string str1; // 단일문자 상수 'char' 입력 불가, 문자열 "string" 입력

    cout << "input \"Hello World!\" used by cin is : ";
    cin >> cinarr; // cin 함수는 화이트 스페이스를 제외한 갑을 가져오고, 개행문자를 입력 버퍼에 남겨둔다
    cout << cinarr << endl;
    cin.getline(cinarr, sizeof(cinarr));
    cout << "input \"Hello World!\" used by cin.getline is : ";
    cin.getline(cinarr, 20); //istream 라이브러리에 포함 n-1개 까지 읽고 n번째 '\0', cin.getline(char *str, streamsize n, char dlim)
    cout << cinarr << endl;
    cout << "input \"Hello World!\" used by getline is : ";
    getline(cin, str1); //string 라이브러리에 포함, getline(istream& is, string str, char dlim);
    cout << str1 << endl;
}