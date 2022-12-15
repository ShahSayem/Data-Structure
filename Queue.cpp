#include<iostream>
using namespace std;

void enqueue();
void dequeue();
void display();

bool cls = true;

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front, *rear, *temp;
int node;

int main()
{
    front = rear = temp = NULL;

    while(1)
    {
        if (cls)
            system("CLS");

        cout<<"\t\t\t\t\t\t\tQueue by Sayem:"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t1. Enqueue"<<endl;
        cout<<"\t\t\t\t\t\t\t2. Dequeue"<<endl;
        cout<<"\t\t\t\t\t\t\t3. Display"<<endl;
        cout<<"\t\t\t\t\t\t\tOr any key to exit"<<endl;
        cout<<endl<<"\t\t\t\t Enter your option : ";
        int option;
        cin>>option;
        cout<<endl;

        switch(option)
        {
        case 1:
        {
            cout<<"\t\t\t\tHow many node you want to enter : ";
            cin>>node;

            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }

        case 3:
        {
            display();
            break;
        }

        default :
        {
            cout<<"\t\t\t\tExited from program"<<endl;
            exit(1);
            break;
        }
        }
    }
}

void enqueue()
{
    cout<<endl<<"\t\t\t\tEnter value to enqueue: ";
    for(int i=0; i<node; i++){
        temp = (Node*) malloc (sizeof(Node));

        cin>>temp->data;
        temp->next = NULL;
        
        if (front == NULL && rear == NULL)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    cls = true;
}

void dequeue()
{
    if (front == NULL)
        cout<<"\t\t\t\t\t\tSorry!!! Queue is already empty"<<endl<<endl;
    
    temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    temp = NULL; 

    cls = true;
}

void display()
{
    cout<<"\t\t\t\t\t\t";
    if (front == NULL){
        cout<<"Sorry!!! Queue is already empty"<<endl<<endl;
        cls = false;
        return;
    }
    temp = front;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl;

    cls = false;
}
