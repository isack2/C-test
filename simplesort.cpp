#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int size;
    int temp;
    int *num = new int;
    vector<int> bucket;
    

    cin >> size;
    for(int i = 0 ; i < size ; i++){
        cin >> num[i];
    }

    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(num[i] < num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp; 
            }
        }
    }

    for(int i = 0 ; i < size ; i++){
        cout << num[i] << endl;
    }

    delete num;
}