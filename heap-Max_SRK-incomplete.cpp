#include <iostream>
using namespace std;

int arr[10], SIZE = 0;
void maxHeapInsert(int newNumber);
void heapify(int parentIndex);
void maxHeapDelete(int newNumber);
void swapVal(int a, int b);

int main()
{
    int node;
    cout<<"How many veretx you want to insert in heap: ";
    cin>>node;

    cout<<"\nEnter verteces: ";
    while (node--){
        int x;
        cin>>x;
        maxHeapInsert(x);
    }

    for (int i = 0; i < SIZE; i++){
        cout<<arr[i]<<" ";
    }   
}

void maxHeapInsert(int newNumber)
{

    arr[SIZE] = newNumber;
    SIZE++; 

    for (int parentIndex = SIZE/2 -1; parentIndex >= 0; parentIndex--){ 
        heapify(parentIndex);
    }
    
}

void heapify(int parentIndex)
{
    int largest = parentIndex;
    int leftChild = 2*parentIndex + 1;
    int rightChild = 2*parentIndex + 2;

    if (leftChild < SIZE && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if (rightChild < SIZE && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }

    if (largest != parentIndex){
        swapVal(largest, parentIndex);
    }
}

void swapVal(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxHeapDelete(int newNumber)
{

}