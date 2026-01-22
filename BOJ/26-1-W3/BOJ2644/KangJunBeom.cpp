#include <bits/stdc++.h>
using namespace std;

int n;
int tx, ty;
int t;
int parent, child;
bool visited[101];
vector<int> v[101];

void dfs(int start, int depth){

    visited[start]=true;

    for(auto a : v[start]){
        if(visited[a]) continue;
        if(a == ty){
            cout << depth+1;
            exit(0);
        }
        dfs(a,depth+1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> tx >> ty;
    cin >> t;
    
    for(int i = 0; i<t; ++i){
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    dfs(tx,0);
    if(!visited[ty]){
        cout << -1;
    }
    
    return 0;
}