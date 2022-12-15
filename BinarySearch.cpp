#include <iostream>
using namespace std;

void BinarySearch(int x, int arr[], int n){

    int start = 0, endd = n-1;
    while (start <= endd){
        int mid = (start+endd)/2;

        if(arr[mid] == x){
            cout<<"Found"<<endl<<"Index: "<<mid<<endl;
            return;
        }
        else if(arr[mid] > x){
            endd = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout<<"Not found!!!"<<endl;
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

    BinarySearch(num, a, n);

    return 0;
}