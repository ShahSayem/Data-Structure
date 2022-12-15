#include <iostream>
using namespace std;

int arr[10], size = 0;
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

    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    
}

void maxHeapInsert(int newNumber)
{
    if (size == 0){       //insert
        arr[0] = newNumber;
        size++;
    }
    else {
        arr[size] = newNumber;
        size++; 
    }

    for (int parentIndex = size/2 -1; parentIndex >= 0; parentIndex--){ 
        heapify(parentIndex);
    }
    
}

void heapify(int parentIndex)
{
    int largest = parentIndex;
    int leftChild = 2*parentIndex + 1;
    int rightChild = 2*parentIndex + 2;

    if (leftChild < size && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest]){
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