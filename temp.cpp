#include<iostream>
#include<cstring>
#include<string>
#define SIZE 100

int main(){
    int count = 0;
    int i = 0;
    char arr[SIZE] = {0};
    char tarr[SIZE] ={0};

    std::cin.getline(arr, SIZE);
    std::cout << arr << std::endl;

    for(int i = 0 ; i < 5 ; i++){
        tarr[i] = arr[6 + i];
    }
    std::cout << tarr << std::endl;

     /*while(count < SIZE){
        if(arr[count] != ' '){
            tarr[i] = arr[count];
            count++;
            i++;
            }
        else{
            std::cout << tarr << std::endl;
            std ::cout << count << std::endl;
            while(arr[count] == ' '){
                count++;
            }
            i = 0;
        }
        std::cout << "count: " << count << std::endl; //if문을 완료하고 넘어옴
        std::cout << "i: " << i << std::endl;
        continue;
    }*/
}