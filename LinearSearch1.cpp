#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 4, 7, 2, 3}, num;

    cout<<"Enter a value:"; 
   // printf("Enter a value: ");
    cin>>num;

    bool check = false; // x = 0
    for (int i = 0; i < 5; i++){
        if(a[i] == num){
            cout<<"Found"<<endl<<"Position: "<<i<<endl;
            check = true; //x = 1
            break;
        }
    }

    if (!check) // if(x == 0)
    {
        cout<<"Not found!"<<endl;
    }
    

    return 0;
}