#include <iostream>
using namespace std;

void Print_array(int num[])
{
    cout<<"Numbers: ";
    for (int i = 0; i < 5; i++){
        cout<<num[i]<<" ";
    }

}

int main()
{
    int numbers[5];

    for (int i = 0; i < 5; i++){
        cin>>numbers[i];
    }

    Print_array(numbers);

    return 0;
}