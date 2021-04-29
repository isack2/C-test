#include<iostream>
#include<cstring>

int main(void){
    using namespace std;
    char temparr[10];
    int i = 0;
    int tempint1;

    cin >> temparr;
    while(atoi(temparr) == 0){
        cout << "not number" << endl;
        cin >> temparr;
    }
    tempint1 = atoi(temparr);
    cout << tempint1 << endl;
}
