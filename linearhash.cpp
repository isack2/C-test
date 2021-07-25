#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
#define TABLESIZE 10007
#define INPUTSIZE 5000

typedef struct _User{
    int index;
    char username[20] = {};
}User;

void insert(User **, int, User *);
int searchempty(User **, int);
void show(User **);

int main(void){
    User **hash = new User *[TABLESIZE];
    for(int i = 0 ; i < TABLESIZE ; i++){ 
        hash[i] = nullptr;
    }

    for(int i = 0 ; i < INPUTSIZE ; i++){
        User *user = new User;
        int randnum = rand() % 100000;
        int indexnum = searchempty(hash, randnum);
        user->index = indexnum;
        sprintf(user->username, "User: %d", randnum);
        insert(hash, indexnum, user);
    }

    show(hash);
    
    for(int i = 0 ; i < TABLESIZE ; i++){
        delete hash[i];
    }
    delete [] hash;
}

void insert(User **hash, int index, User *data){
    if(hash[index] == nullptr){
        hash[index] = new User;
        hash[index] = data;
    }
    else{
        index = searchempty(hash, index);
        hash[index] = new User;
        hash[index] = data;
    }
}

int searchempty(User **hash, int index){
    int temp = index % TABLESIZE;
    if(hash[temp] == nullptr){
        return temp;
    }
    else{
        while(hash[temp] != nullptr){
            temp++;
        }
    return temp;
    }
}

void show(User **hash){
    for(int i = 0 ; i < TABLESIZE ; i++){
        if(hash[i] != nullptr){
            cout << "Index: " << hash[i]->index << ",    " << "Name: " << hash[i]->username << endl;
        }
        else{
            cout << "Index " << i << " empty" << endl;
        }
    }
}
