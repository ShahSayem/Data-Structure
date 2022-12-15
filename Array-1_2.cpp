#include <iostream>
using namespace std;

void Print_pointer_array(int *p)
{
    cout<<"Pointer Numbers: ";
    for (int i = 0; i < 5; i++){
        cout<<*(p++)<<" ";
    }
    cout<<endl;
}

void Print_array_using_pointer(int *p)
{
    cout<<"Array Numbers using pointer: ";
    for (int i = 0; i < 5; i++){
        cout<<*(p++)<<" ";
    }
}
int main()
{
    int numbers[5];
    int *ptr = numbers;

    cout<<ptr<<"\t"<<numbers<<endl;

    for (int i = 0; i < 5; i++){
        cin>>numbers[i];
    }

    Print_pointer_array(ptr);
    Print_array_using_pointer(numbers);

    return 0;
}