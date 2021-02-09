#include<iostream>
#include<cstdlib>

int main(void){

    using namespace std;
    srand(time(NULL));
    int count;
    cout << "숫자를 입력해 주세요 : ";
    cin >> count;
    int arr[count];

    if(count > 45){
        std::cout << "45보다 작은수를 입력해 주세요";
    }
    else{
        for(int i = 0 ; i < count ; i ++){
        int temp = (rand() % 45 + 1);
        if(i == 0){
            arr[i] = temp;
        }
        else{
            int j = 0;
            while(j < i){
                if((arr[j] - temp) != 0){
                    j++;
                }
                else{
                    temp = rand() % 45 + 1;
                    j = 0;
                    }
                    arr[i] = temp;
            }
        }
    }
    } 

    for(int i = 0 ; i < count ; i++){
        cout << i+1 << " number is :" << arr[i] << endl;
    }
}
