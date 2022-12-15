#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};

void AddEnd(struct node *head, int data);
struct node* AddFirst(struct node *head, int data);
void Print(struct node *head);

int main(){

    struct node *head = NULL;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node*) malloc(sizeof(struct node));
    current->data =  98;
    current->link = NULL;
    head->link = current;

    current = (struct node*) malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
    
    AddEnd(head, 67);
    head = AddFirst(head, 786);
    Print(head);

    return 0;
}

void AddEnd(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*) malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
} 

struct node* AddFirst(struct node *head, int data){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;
    temp->link = head;
    head = temp;
    return head;
}

void Print(struct node *head){
    struct node *ptr;
    ptr = head;
    while (ptr != NULL){
        cout<<ptr->data<<"\t";
        ptr = ptr->link;
    } 
}