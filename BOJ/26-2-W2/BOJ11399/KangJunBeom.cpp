#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    int n;
    int sum = 0;
    cin >> n;
    for(int i =0; i<n; ++i){
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
   
    for(int i = 1; i<n; ++i){
        a[i] += a[i-1];    
    }

    for(int i =0;i<n; ++i){
        sum += a[i];
    }
    
    cout << sum;
}