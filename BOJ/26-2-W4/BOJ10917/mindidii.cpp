// Your Life

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
const int INF = 1e9;
vector<int> dream[100001]; 
vector<int> visit;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < dream[curr].size(); i++)
        {
            int nxt = dream[curr][i];
            
            if (visit[nxt] == -1)
            {
                visit[nxt] = visit[curr] + 1;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
            dream[u].push_back(v);
            dream[v].push_back(u);
        
    }

    visit.assign(N + 1, -1);
    bfs(1);

    if (visit[N] == -1) {
        cout << -1;
    } else {
        cout << visit[N];
    }

    return 0;
}