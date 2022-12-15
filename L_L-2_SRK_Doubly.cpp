#include <iostream>
using namespace std;

void Create();
void Display();
void LinearSearch();
void Update();
void InsertBeginning();
void InsertPosition();
void InsertEnd();
void DeleteFirst();
void DeleteLast();
void DeletePosition();
void DeleteList();
 

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}Node;

Node *head, *temp, *tail;

int main()
{
    head = temp = tail = NULL;

    Create();
    Display();
    LinearSearch();
    Update();
    InsertBeginning();
    InsertPosition();
    InsertEnd();
    Display();
    DeletePosition();
    DeleteFirst();
    DeleteLast();
    Display();
    DeleteList();
    Display();
    
    return 0;
}

void Create()
{
    int n;
    cout<<"Enter number of node: ";
    cin>>n;

    cout<<"Enter node value: ";
    for (int i = 0; i < n; i++){
        temp = (Node*) malloc(sizeof(Node));
        cin>>temp->data;
        temp->prev = temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
        }
        tail = temp;
    }
}

void InsertEnd()
{
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter data to Insert end: ";
    cin>>temp->data;
    temp->next = NULL;

    tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;
}

void Display()
{
    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        temp = head;
        cout<<endl<<"Linked List's data: "<<endl;
        while (temp != NULL){
            cout<<"Address of previous node: "<<temp->prev<<"\tAddress of node: "<<temp<<"\tData: "<<temp->data<<"\t\tAddress of next node: "<<temp->next<<endl;
            temp = temp->next;
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
        tail = tail->next;
    }
    
    if (check){
        cout<<"Found!!!\t"<<"Total iteration needed: "<<i<<endl;
    }
    else{
        cout<<"Not found (-_-)"<<endl;
    }
}

void InsertBeginning()
{
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter data to Insert beginning: ";
    cin>>temp->data;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;

    head = temp;
}

void InsertPosition()
{
    int pos;
    temp = (Node*) malloc(sizeof(Node));
    cout<<"Enter your desired data position: ";
    cin>>pos;
    cout<<"Enter data to Insert in position "<<pos<<": ";
    cin>>temp->data;

    tail = head;
    for (int i = 1; i < pos; i++){
        tail = tail->next;
    }
    temp->prev = tail;
    temp->next = tail->next;
    tail->next->prev = temp;
    tail->next = temp;
}

void DeleteFirst()
{
    if(head == NULL){
        cout<<"List is already empty !!!"<<endl;
    }
    else{
        tail = head;
        head = head->next;
        head->prev = NULL;
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
        while (tail->next != NULL){
            temp = tail;
            tail = tail->next;
        }
        temp->next = NULL;
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
            temp = temp->next;
        }
        tail->next = temp->next;
        tail->next->prev = tail;

        free(temp);
        temp = NULL;  
    }
}

void DeleteList()
{
    temp = head;

    while (temp != NULL){
        temp = temp->next;
        free(head);
        head = temp;
    }   
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
        tail = tail->next;
    }  
    tail->data = num;
}