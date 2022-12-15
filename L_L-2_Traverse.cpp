#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};

void CountNode(struct node *head);

int main(){

    struct node *head = NULL;
    head = (struct node *) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->data =  98;
    current->link = NULL;
    head->link = current;

    current = (struct node *) malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
    
    CountNode(head);

    return 0;
}

void CountNode(struct node *head){
    int count = 0;
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
    }

    struct node *ptr = NULL;
    ptr = head;
    cout<<"Data on the Linked List: "<<endl;
    while (ptr != NULL){
        count++;
        cout<<ptr->data<<"\t";
        ptr = ptr->link;
    }
    cout<<endl<<"Number of nodeas: "<<count<<endl;
    
}