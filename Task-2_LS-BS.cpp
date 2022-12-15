#include <iostream>
using namespace std;

int LinearSearch(int x, int arr[], int n);
int BinarySearch(int x, int arr[], int n);


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

    int p = LinearSearch(num, a, n);
    int q = BinarySearch(num, a, n);

    if(p > q){
        cout<<endl<<"*** BinarySearch is most efficient here \3"<<endl;
    }
    else{
        cout<<endl<<"*** LinearSearch is most efficient here \3"<<endl;
    }

    return 0;
}

int LinearSearch(int x, int arr[], int n)
{

    cout<<endl<<"# Result from LinearSearch: "<<endl;

    bool check = false;
    int count = 0;
    for (int i = 0; i < n; i++){
        count++;
        if(arr[i] == x){
            cout<<"Found"<<endl<<"Index: "<<i<<endl;
            cout<<"Itration needed: "<<count<<endl;
            check = true;
            break;
        }
    }

    if (!check){
        cout<<"Not found!!!"<<endl;
        cout<<"Itration needed: "<<count<<endl;
    }
    return count;
}

int BinarySearch(int x, int arr[], int n)
{

    cout<<endl<<"# Result from BinarySearch: "<<endl;

    int start = 0, endd = n-1;
    int count = 0;

    bool check = false;
    while (start <= endd){
        count++;
        int mid = (start+endd)/2;

        if(arr[mid] == x){
            cout<<"Found"<<endl<<"Index: "<<mid<<endl;
            cout<<"Itration needed: "<<count<<endl;
            check = true;
            break;
        }
        else if(arr[mid] > x){
            endd = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if (!check){
        cout<<"Not found!!!"<<endl;
        cout<<"Itration needed: "<<count<<endl;
    }

    return count;
}