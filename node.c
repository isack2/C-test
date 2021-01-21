#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *head, *tail, *node1, *node2;

void new(int);
void del(int);
void show(void);
void afree(void);

int main(void){

    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));

    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
    head->data = -10000;
    tail->data = 10000;
    
    new(8);
    new(2);
    del(1);
    new(4);
    new(6);
    new(1);
    del(2);
    new(7);
    new(9);
    del(4);
    new(3);
    new(2);
    show();
    afree();

    free(head);
    free(tail);
}

void new(int data){
    Node *current = head -> next;
    while((current->data < data) && (current != tail)){
        current = current->next;
    }
    Node *back = current->prev;
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    back->next = new;
    new->prev = back;
    new->next = current;
    current->prev = new;
}

void del(int count){
    int tempcount = 1;
    Node *current = head->next;
    while(tempcount < count){
        current = current->next;
        tempcount++;
    }
    Node *back = current->prev;
    Node *next = current->next;
    back->next = next;
    next->prev = back;
    free(current);
}


void afree(void){
    Node *current = head->next;
    while(current != tail){
        current = current->next;
        Node *del = current->prev;
        free(del);
    }
}

void show(void){
    Node *current = head->next;
    printf("*head*\n");
    while(current != tail){
        printf("%d\n", current->data);
        current = current->next;
        }
        printf("*tail*\n");
}


