// solved(BOJ2644 / S2): 촌수계산
// bfs 사용

#include <bits/stdc++.h>

using namespace std;
#define MAX 105

int main() {
    int N;
    int M;
    int target_x;
    int target_y;
    int cnt=0;
    int arr[MAX][MAX];
    int visited[MAX];
    queue<int> q;
    cin >> N;
    cin >> target_x >> target_y;
    cin >> M;
    for(int i=0;i<M;i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    q.push(target_x);
    while(!q.empty()) {
        target_x = q.front();
        q.pop();
        for(auto i=1;i<=N;i++) {
            if(arr[target_x][i]!=0 && !visited[i]) {
                q.push(i);
                visited[i]=visited[target_x]+1; 
            }
        }
    }
    if(visited[target_y]==0)
        visited[target_y]=-1;
    cout << visited[target_y];
}