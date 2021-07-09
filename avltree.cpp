#include<iostream>
using namespace std;


typedef struct _Node{
    _Node *left = nullptr;
    _Node *right = nullptr;
    int data = 0;
    int height = 0;
}Node;

int getheight(Node *);
int getmax(int, int);
void setheight(Node *);
int getdifference(Node *);
Node *LLrot(Node *);
Node *RRrot(Node *);
Node *LRLrot(Node *);
Node *RLrot(Node *);
Node *balance(Node *);
Node *insertnode(Node *, int);
void display(Node *, int);

Node *root = nullptr;

int main(void){

    root = insertnode(root, 7);
    root = insertnode(root, 8);
    root = insertnode(root, 9);
    root = insertnode(root, 1);
    root = insertnode(root, 2);
    root = insertnode(root, 4);
    root = insertnode(root, 6);
    root = insertnode(root, 3);
    root = insertnode(root, 12);
    root = insertnode(root, 20);
    root = insertnode(root, 15);
    root = insertnode(root, 17);
    root = insertnode(root, 5);
    root = insertnode(root, 23);
    root = insertnode(root, 14);

    display(root, 1);
    cout << endl;
}

int getheight(Node *target){
    if(target == nullptr) 
        return 0;
    return target->height;
}

int getmax(int num1, int num2){
    int val = num1 > num2 ? num1 : num2;
    return val;
}

void setheight(Node *target){
    target->height = getmax(getheight(target->left), getheight(target->right)) + 1;
}

int getdifference(Node *target){
    if(target == nullptr)
        return 0;
    return (getheight(target->left) - getheight(target->right));
}

Node *LLrot(Node *target){
    Node *left = target->left;
    target->left =left->right;
    left->right = target;
    setheight(target);
    return left;
}

Node *RRrot(Node *target){
    Node *right = target->right;
    target->right = right->left;
    right->left = target;
    setheight(target);
    return right;
}

Node *LRrot(Node *target){
    Node *left = target->left;
    target->left = RRrot(left);
    setheight(left);
    return LLrot(target);
}

Node *RLrot(Node *target){
    Node *right = target->right;
    target->right = LLrot(right);
    setheight(right);
    return RRrot(target);
}

Node *balance(Node *target){
    int difference = getdifference(target);
    if (difference >= 2){
        if(getdifference(target->left) >= 1){
            target = LLrot(target);
        }
        else
            target = LRrot(target);
    }
    else if(getdifference(target) <= -2){
        if(getdifference(target->right) <= -1){
            target = RRrot(target);
        }
        else
            target = RLrot(target);
    }
    setheight(target);
    return target;
}

Node *insertnode(Node *target, int data){
    if(target == nullptr){
        target = new Node;
        target->data = data;
        target->height = 1;
    }
    else if(target->data > data){
        target->left = insertnode(target->left, data);
        target = balance(target);
    }
    else if(target->data < data){
        target->right = insertnode(target->right, data);
        target = balance(target);
    }
    else
        cout << "data duplicated!" << endl;
    return target;
}

void display(Node *target, int level){
    if(target != nullptr){
        display(target->right, level + 1);
        cout << endl;
        if(target == root){
            cout << "root: ";
        }
        for(int i = 0 ; i < level && target != root ; i++){
            cout << "     ";
        }
        cout << target->data << "(" << getheight(target) << ")";
        display(target->left, level + 1);
    }
}