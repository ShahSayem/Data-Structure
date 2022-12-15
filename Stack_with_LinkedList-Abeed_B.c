#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *top,*temp,*tail;
int main()
{   
    top = 0;
    
    int choice;
    while(choice!=5){
    printf("\n\n\n\n1.Push\n2.Pop\n3.peek\n4.display");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
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
            peek();
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            printf("Existed from the program.");
            break;
        }
        default :
        {
            printf("\nInvalid Choice.");
            break;
        }
    }
    }
    
}
void push()
{
    temp = (Node*)malloc(sizeof(Node));
    printf("Enter the data you want to push :");
    scanf("%d",&temp->data);
    temp->next = top;
    top = temp;
}
void pop()
{
    tail = top;
    top = top->next;
    tail->next = NULL;
    free(tail);
    display(); 
}
void display()
{
    if(top==0)
    {
        printf("Stack is empty.");
    }
    else{
        tail = top;
        printf("The stack values are :");
        while(tail!=0)
        {
            printf("%d  ",tail->data);
            tail = tail->next;
        }
    }
}
void peek()
{
    printf("The top value is : %d",top->data);
}