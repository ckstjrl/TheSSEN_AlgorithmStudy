#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>, greater<int>> pq;
int n, tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i<n; ++i){
        cin >> tmp;
        if(tmp != 0) pq.push(tmp);
        else{
            if(pq.empty()){
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}