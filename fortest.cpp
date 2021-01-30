#include<iostream>
#include<cstdlib>

int main(void){

    using namespace std;
    int arr[6] = {1,2,3,4,5,6};
    int temparr[6] = {0};
    int sum = 0;

    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(arr[j] != 23){
                temparr[j] = 9;
            }
            else{
                temparr[j] = 4;
            }
        }
        cout << i << ":";

        for(int k = 0 ; k <= i ; k++){
            cout << temparr[k];
        }
        cout << endl;
    }
    cout << endl;

    for(int s = 0 ; s <= 6 ; s++){
        sum = sum + temparr[s];
        cout << "sum : " << sum << endl;
    }

    retrun 0;
}


     if(sum == 0){
                    data[i] = temp;
                    }
                    else{
                        std::cout << "onemore!" << std::endl;
                        }
                    }
                    i = i;