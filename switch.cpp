#include<iostream>

int main(void){

    using namespace std;

    int index = 0;
    cout << "번호를 입력 하세요 : ";
    cin >> index;

        switch(index){
            case 0 : cout << "0번 입니다." << endl;
            break;

            case 1 : cout << "1번 입니다." << endl;
            break;

            case 2: cout << "2번 입니다." << endl;
            break;
        }
}