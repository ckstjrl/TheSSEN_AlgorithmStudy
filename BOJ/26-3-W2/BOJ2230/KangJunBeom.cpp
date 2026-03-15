#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for(int& i : v){
        cin >> i;
    }

    sort(v.begin(), v.end());
    int en = 0;
    int mini = INT_MAX;
    for(int st = 0; st<N; ++st){
        while(en < N && v[en]-v[st] < M){
            en++;
        }
        
        if(en==N) break;
        
        mini = min(mini, v[en]-v[st]);
        
    }

    cout << mini;
}