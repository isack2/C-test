#include<iostream>
using namespace std;

typedef struct _Node
{
    int data = 0;
    int depth = 0;
    _Node *left = nullptr;
    _Node *right = nullptr;
    
}Node;

Node* insertnode(Node *, int);
void preorder(Node *);
Node *findmin(Node *);
Node *searchdepth(Node *, int);
Node *deletenode(Node *, int);

int main(void){
    Node *root = nullptr;
    Node *min = nullptr;

    root = insertnode(root, 30);
    root = insertnode(root, 17);
    root = insertnode(root, 48);
    root = insertnode(root, 5);
    root = insertnode(root, 23);
    root = insertnode(root, 37);
    root = insertnode(root, 50);
    root = insertnode(root, 3);
    root = deletenode(root, 50);
    preorder(root);
    cout << endl;

    delete root;
}

Node* insertnode(Node *root, int dat){
    if(root == NULL){
        root = new Node;
        root->data = dat;
        root->left = root->right = NULL;
        return root;
    }
    else{
        if(root->data > dat){
            root->left = insertnode(root->left, dat);
            }
        else{
            root->right = insertnode(root->right, dat);
            }
    }
    return root;
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    else{
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

Node *findmin(Node *root){
    Node *node = root;

    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

Node *searchdepth(Node *root, int dat){
    Node *node = root;

    if(node == nullptr){
        return nullptr;
    }
    else if(node->data == dat){
        return node;
    }
    else{
        if(node->data > dat){
            node = searchdepth(node->left, dat);
            node->depth = node->depth + 1;
        }
        else{
            node = searchdepth(node->right, dat);
            node->depth = node->depth + 1;
        }
    }
    return node;
}

Node *deletenode(Node *root, int dat){
    Node *node = nullptr;

    if(root == nullptr){
        return nullptr;
    }
    else if(root->data > dat){
        root->left = deletenode(root->left, dat);
    }
    else if(root->data < dat){
        root->right = deletenode(node->right, dat);
    }
    else{
        if(root->left != nullptr && root->right != nullptr){
            node = findmin(root->right);
            root->data = node->data;
            root->right = deletenode(root->right, node->data);
        }
        else if(root->left != nullptr){
            node = root->left;
            root->data = node->data;
            delete root;
            return node; //없으면 노드가 안 없어짐 이유 모름
        }
        else if(root->right != nullptr){
            node = root->right;
            root->data = node->data;
            delete root;
            return node; //없으면 노드가 안 없어짐 이유 모름
        }
        else{
            delete root;
            return node; //없으면 노드가 안 없어짐 이유 모름
        }
    }
    return root ;
}