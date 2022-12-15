#include <bits/stdc++.h>
using namespace std;

vector <int> solve(vector <int> & temperatures){
    vector <int> ans;
    
    auto it = temperatures.begin();
    for (int i = 0; i < temperatures.size(); i++){
        int index = upper_bound(it, temperatures.end(), temperatures[i])-temperatures.begin();
        if (temperatures[index] > temperatures[i]){
            // index -= i;
            ans.push_back(index);
        }
        else{
            ans.push_back(0);
        }
        it++;
    }
    
    return ans;
}

int main()
{
    vector <int> temperatures;
    int x;

    while (cin>>x) {
        temperatures.push_back(x);
    }

    vector <int> ans = solve(temperatures);

    for(auto w:ans)
        cout<<w<<" ";
    
    return 0;
}