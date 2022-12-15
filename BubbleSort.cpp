#include <iostream>
using namespace std;

void BubbleSort(int arr[], int num);

int main()
{
    int n;
    cout<<"Element number:";
    cin>>n;

    int a[n];

    cout<<"Enter elements:";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    BubbleSort(a, n);

    return 0;
}

void BubbleSort(int arr[], int num){
    int count = 1;
    while(count<num){
        for (int i = 0; i < num-count; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        count++;
    }
    
    for (int i = 0; i < num; i++){
        cout<<arr[i]<<" ";
    }
}