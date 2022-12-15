#include <iostream>
using namespace std;

void CreatLL();
void Print();
void LinearSearch();
void AddLast();
void AddFirst();
void AddPosition();
void DeleteFirst();
void DeleteLast();
void DeletePosition();
void DeleteList();
void ReverseList();
void Update(); 

typedef struct node {
    int data;
    struct node *link;
}Node;

Node *head, *temp, *tail;

int main()
{
    head = temp = tail = NULL;

    CreatLL();
    AddFirst();
    AddPosition();
    AddLast();
    Print();
    DeleteFirst();
    DeletePosition();
    DeleteLast();
    Print();
    LinearSearch();
    DeleteList();
    Print();
    CreatLL();
    Print();
    ReverseList();
    Print();
    Update();
    Print();

    return 0;
}

void CreatLL()
{
    int n;
    cout<<"Enter number of node: ";
    cin>>n;

    cout<<"Enter node value: ";
    for (int i = 0; i < n; i++){
        temp = (Node*) malloc(sizeof(Node));
        cin>>temp->data;
        temp->link = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            tail->link = temp;
        }
        tail = temp;
    }
}

void AddLast()
{
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter data to add last: ";
    cin>>temp->data;
    temp->link = NULL;

    tail = head;
    while (tail->link != NULL){
        tail = tail->link;
    }
    tail->link = temp;
}

void Print()
{
    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        temp = head;
        cout<<endl<<"Linked List's data: "<<endl;
        while (temp != NULL){
            cout<<"Address of node: "<<temp<<"\tData: "<<temp->data<<"\t\tAddress of next node: "<<temp->link<<endl;
            temp = temp->link;
        }
    }
}

void LinearSearch()
{
    int num;
    cout<<endl<<"Enter a data to search: ";
    cin>>num;

    tail = head;

    int i;
    bool check = false;
    for (i = 1; tail != NULL; i++){
        if(tail->data == num){
            check = true;
            break;
        }
        tail = tail->link;
    }
    
    if (check){
        cout<<"Found!!!\t"<<"Total iteration needed: "<<i<<endl;
    }
    else{
        cout<<"Not found (-_-)"<<endl;
    }

}

void AddFirst()
{
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter data to add first: ";
    cin>>temp->data;
    temp->link = head;

    head = temp;
}

void AddPosition()
{
    int pos;
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter your desired data position: ";
    cin>>pos;
    cout<<"Enter data to add in position "<<pos<<": ";
    cin>>temp->data;
    temp->link = NULL;

    tail = head;

    for (int i = 1; i < pos; i++){
        tail = tail->link;
    }
    temp->link = tail->link;
    tail->link = temp;
}

void DeleteFirst()
{
    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        tail = head;
        head = head->link;
        free(tail);
        tail = NULL;
    }
}

void DeleteLast()
{
    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        tail = head;
        temp = head;
        while (tail->link != NULL){
            temp = tail;
            tail = tail->link;
        }
        temp->link = NULL;
        free(tail);
        tail = NULL;
    }
}

void DeletePosition()
{
    int num;
    cout<<"Enter a data to delete: ";
    cin>>num;

    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        temp = head;
        while (temp->data != num){
            tail = temp;
            temp = temp->link;
        }
        tail->link = temp->link;

        free(temp);
        temp = NULL;  
    }
}

void DeleteList()
{
    temp = head;

    while (temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }   
}

void ReverseList()
{
    temp = tail = NULL;
    while (head != NULL){
        tail = head->link;
        head->link = temp;
        temp = head;
        head = tail;
    }
    head = temp;
}

void Update()
{
    int num, pos;
    cout<<endl<<"Enter a data to update: ";
    cin>>num;
    cout<<"Enter position: ";
    cin>>pos;

    tail = head;

    for (int i = 0; i < pos; i++){
        tail = tail->link;
    }  
    tail->data = num;
}