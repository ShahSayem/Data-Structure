#include <bits/stdc++.h>
using namespace std;

int solve(vector <int> & nums, int target){
    int index = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    
    return index;
}

int main()
{
    vector <int> nums;
    int x, key;
    cin>>key;

    while (cin>>x) {
        nums.push_back(x);
    }

    cout<<solve(nums, key);
    
    return 0;
}