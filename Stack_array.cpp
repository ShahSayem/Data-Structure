#include <iostream>
using namespace std;

int top = -1;

#define MAX 5
int stack_arr[MAX];

bool cls = true;

void push(int data);
void pop();
void print();
void peek();
int main()
{
    while (1){
        if(cls){
            system("CLS");
        }
        cout<<"\t\t\t\t\t\t\tStack by Sayem:"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t1. Push"<<endl;
        cout<<"\t\t\t\t\t\t\t2. Pop"<<endl;
        cout<<"\t\t\t\t\t\t\t3. Print top element"<<endl;
        cout<<"\t\t\t\t\t\t\t4. Print all element"<<endl;
        cout<<"\t\t\t\t\t\t\t5. Quit"<<endl;
        int z;
        cout<<endl<<"\t\t\t\t Enter Option: ";
        cin>>z;
        cout<<endl;

        switch (z){
        case 1:
        {
            cout<<"\t\t\t\tHow many data do you want to push: ";
            int p, i;
            cin>>p;
            cout<<"\t\t\t\tEnter data to push: ";
            for (i = 0; i < p; i++){
                int data;
                cin>>data;
                push(data);
            }
            break;
        }
        case 2:
        {
            cout<<"\t\t\t\tHow many data do you want to pop: ";
            int x, i;
            cin>>x;
            for (i = 0; i < x; i++){
                pop();
            }
            cout<<"\t\t\t\tNumber of poped value: "<<i<<endl;
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            print();
            break;
        }
        case 5:
        {
            cout<<"\t\t\t\tExit from program!!!"<<endl;
            exit(1);
            break;
        }
        default:
            cout<<"\t\t\t\tOption did not match (-_-)"<<endl;
            break;
        }
    }
    
    return 0;
}

void push(int data)
{
    if(top >= MAX-1){
        cout<<"\t\t\t\tStack is full!!!"<<endl;
        cls = false;
        return;
    }
    top++;
    stack_arr[top] = data;
}

void pop()
{
    if(top == -1){
        cout<<"\t\t\t\tStack is empty!!!"<<endl;
        cls = false;
        return;
    }
    top--;
}

void print()
{
    cls = false;

    if(top == -1){
        cout<<"\t\t\t\tStack is empty!!!"<<endl;
        return;
    }

    cout<<"\t\t\t\tStack values: ";
    for (int i = top; i > -1; i--){
        cout<<stack_arr[i]<<" ";
    }
    cout<<endl;
}

void peek()
{
    cls = false;
    
    if(top == -1){
        cout<<"\t\t\t\tStack is empty!!!"<<endl;
        return;
    }
    cout<<"\t\t\t\tThe top value is :"<<stack_arr[top]<<endl;
}

