#include <bits/stdc++.h>
using namespace std;

vector<int> go[501];
bool visited[501];
int N, num, v, u, ans;

void bfs(){
    queue<pair<int, int>> q;
    q.push({1,0});
    visited[1] = true;

    while(!q.empty()){
        int next = q.front().first;
        int depth = q.front().second;
        q.pop();
        for(int a : go[next]){
            if(visited[a]) continue;
            q.push({a,depth+1});
            visited[a] = true;
            if(depth<2){
                ans++;
            }
        }
    }
}

int main(){
    cin >> N;
    cin >> num;
    for(int i= 0; i<num; ++i){
        cin >> u >> v;
        go[u].push_back(v);
        go[v].push_back(u);
    }

    bfs();
    cout << ans;
}