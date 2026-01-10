#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int visited[1001];

void BFS(int n){

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int go = q.front();
        q.pop();

        for(int i =0 ;i<v[go].size();++i){
            if(visited[v[go][i]]==0){
                q.push(v[go][i]);
                visited[v[go][i]]=1;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int a,b;
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i<m; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i<=n; ++i){
        if(visited[i]==0){
            BFS(i);
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}