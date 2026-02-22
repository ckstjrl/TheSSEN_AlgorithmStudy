#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int sx, sy;
int gx, gy;
int n, m;
int route[1001][1001];
bool visited[1001][1001];

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;

    while(q.size()){
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for(int i = 0; i<4; ++i){
            gx = x+dx[i];
            gy = y+dy[i];
            
            if(gy < 0 || gy >= n || gx < 0 || gx >=m) continue;
            if(visited[gy][gx]) continue;
            if(route[gy][gx] == 0)continue;
            
            route[gy][gx] = route[y][x]+1;
            visited[gy][gx] = true;
            q.push({gy,gx});
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> route[i][j];
            if(route[i][j]==2){
                sy = i;
                sx = j;
                route[i][j]=0;
            }
        }
    }

    bfs(sy, sx);

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(route[i][j] == 1 && !visited[i][j]){
                cout << -1 << " ";
            }
            else{
                cout << route[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
}