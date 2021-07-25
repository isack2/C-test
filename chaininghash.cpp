#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
#define INPUTSIZE 3000

typedef struct _User{
    int index;
    char username[20] = {};
}User;

typedef struct _Node{
    User *data;
    _Node *next = nullptr;
}Node;

void insert(Node **, User *, int);
void pop(Node **, int);
void show(Node **);

int main(void){
    Node **hash = new Node *[INPUTSIZE];
    time_t seed;
    srand(seed);
    for(int i = 0 ; i < INPUTSIZE ; i++){ 
        hash[i] = nullptr;
    }

    for(int i = 0 ; i < INPUTSIZE ; i++){
        User *user = new User;
        int randnum = rand() % 100000;
        int indexnum = randnum % INPUTSIZE;
        user->index = indexnum;
        sprintf(user->username, "User: %d", randnum);
        cout << user->index << " " << user->username << endl;
        insert(hash, user, indexnum);
    }

    show(hash);
    
    for(int i = 0 ; i < INPUTSIZE ; i++){
        delete hash[i];
    }
    delete [] hash;
}

void insert(Node **hash, User *data, int index){
    if(hash[index] == nullptr){
        hash[index] = new Node;
        hash[index]->data = data;
    }
    else{
        Node *temp = new Node;
        temp->data = data;
        temp->next = hash[index];
        hash[index] = temp;
    }
}

void pop(Node **hash, int index){
    while(hash[index] != nullptr){
        Node * cur = new Node;
        cur = hash[index];
        cout << "Index: " << cur->data->index << ",    " << "Name: " << cur->data->username << endl;
        hash[index] = hash[index]->next;
        delete cur;
    }
    cout << "Index " << index << " empty" << endl;
}

void show(Node **hash){
    for(int i = 0 ; i < INPUTSIZE ; i++){
        pop(hash, i);
    }
}