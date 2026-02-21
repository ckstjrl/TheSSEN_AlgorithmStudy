#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int>graph[1001];
vector<int>visit;

void dfs(int start)
{
    visit[start] = 1;
    cout << start << ' ';

    for(int i=0; i<graph[start].size(); i++)
    {
        int nxt = graph[start][i];
        if(visit[nxt] == 0) 
        {
            dfs(nxt);
        }
    }

}

void bfs(int start)
{
    queue<int>q;
    q.push(start);
    visit[start] = 1;
    cout << start << ' ';

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i=0; i<graph[curr].size(); i++)
        {
            int nxt = graph[curr][i];
            if(visit[nxt] == 0) // 만약 방문을 하지 않았다면 
            {
                cout << nxt << ' ';
                visit[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    

}

int main()
{
    cin >> N >> M >> V;
    for(int i=0; i<M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<N+1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    visit.assign(1001, 0);
    dfs(V);
    cout << '\n';
    visit.assign(1001, 0);
    bfs(V);

    return 0;
}