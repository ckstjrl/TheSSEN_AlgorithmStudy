#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int,vector<int>, greater<int>> num;
    int n, tmp;
    cin >> n;

    for(int i = 0; i<n*n; ++i){
        cin >> tmp;
        num.push(tmp);
        if(num.size()>n) num.pop();
    }

    cout << num.top();

}