// 쉬운 최단거리, 시작점에서 모든 목표지점까지의 거리를 구하여라 
# include <iostream>
# include <vector>
# include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> visit; // 
pair<int, int> start;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(pair<int,int> s)
{
    queue<pair<int,int>>q;
    q.push({start});
    visit[start.first][start.second] = 0;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(visit[nx][ny] == -1 && graph[nx][ny] == 1)
                {
                    visit[nx][ny] = visit[cx][cy] + 1;
                    q.push({nx, ny});
                }
                
            }

        }

    }
    

}

int main()
{

    cin >> n >> m;
    graph.assign(n, vector<int>(m, -1));
    visit.assign(n, vector<int>(m, -1));
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            
            cin >> a;
            graph[i][j] = a;
            if(a == 2) start = {i,j};
            else if(a == 0) visit[i][j] = 0;
        }
    }

    bfs(start);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}