#include <bits/stdc++.h>
using namespace std;

int grid[100][100];
int dist[100][100]; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char temp;
            cin >> temp;
            grid[i][j] = temp - '0';
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 1;

    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if(0<=nx && nx < N && 0 <= ny && ny < M)
            {
                if(dist[nx][ny] == -1 && grid[nx][ny] == 1)
                {
                    dist[nx][ny] = dist[curr.first][curr.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << dist[N-1][M-1];

    return 0;
}