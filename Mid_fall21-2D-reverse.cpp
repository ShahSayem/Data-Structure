#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = n; j > i; j--){
            a[i][j] = "[]";
            cout<<a[i][j];
        } 
        cout<<endl; 
    }

    return 0;
}