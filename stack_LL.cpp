#include<iostream>
using namespace std;

void push();
void pop();
void display();

bool cls = true;

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top, *temp, *tail;
int node;

int main()
{
    top = temp = tail = NULL;

    while(1)
    {
        if (cls)
            system("CLS");

        cout<<"\t\t\t\t\t\t\tStack by Sayem:"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t1. Push"<<endl;
        cout<<"\t\t\t\t\t\t\t2. Pop"<<endl;
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
            cout<<"\t\t\t\tHow many nodes you want to enter : ";
            cin>>node;

            push();
            break;
        }
        case 2:
        {
            pop();
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

void push()
{
    temp = NULL;
    cout<<endl<<"\t\t\t\tEnter value to push: ";
    for(int i=0; i<node; i++){
        temp = (Node*) malloc (sizeof(Node));

        cin>>temp->data;
        temp->next = top;
        top = temp;
    }

    cls = true;
}

void pop()
{
    temp = top;
    top = top->next;
    free(temp);
    temp = NULL; 

    cls = true;
}

void display()
{
    cout<<"\t\t\t\t\t\t";
    temp = top;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl;

    cls = false;
}
