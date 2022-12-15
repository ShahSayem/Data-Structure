#include <iostream>
using namespace std;

void LinearSearch(int x, int arr[], int n){

    bool check = false;
    for (int i = 0; i < n; i++){
        if(arr[i] == x){
            cout<<"Found"<<endl<<"Position: "<<i<<endl;
            check = true;
            break;
        }
    }

    if (!check){
        cout<<"Not found!"<<endl;
    }

}

int main()
{
    int n;
    cout<<"Element number:";
    cin>>n;

    int a[n], num;

    cout<<"Enter elements:";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    

    cout<<"Enter a value to search:";
    cin>>num;

    LinearSearch(num, a, n);

    return 0;
}