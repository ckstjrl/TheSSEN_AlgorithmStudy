#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i<n; ++i){
        cin >> v[i];
    }
    vector<int> ans(v);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    for (const auto& val : v)
    {
        auto it = lower_bound(ans.begin(), ans.end(), val);
        cout << distance(ans.begin(), it) << ' ';
    }

}   