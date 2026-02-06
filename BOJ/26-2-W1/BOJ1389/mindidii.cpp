// 케빈베이컨
 
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int N, M;
vector<vector<int>>graph;

int bfs(int start)
{
    vector<int>visit(N+1, -1);
    queue<int>q;
    q.push(start);
    visit[start] = 0;
    int sum = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i=0; i<graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            if(visit[next] == -1)
            {
                visit[next] = visit[curr] + 1;
                sum += visit[next];
                q.push(next);
            }
            
        }

    }
    
    return sum;

}

int main()
{
    cin >> N >> M;
    graph.assign(N+1, vector<int>(N+1, 0));

    for(int i=0; i<M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int bacon = 1e9;
    int user = 0;
    for(int i=1; i<N+1; i++)
    {
        int now = bfs(i);
        if(bacon > now)
        {
            bacon = now;
            user = i;
        }
    }

    cout << user << '\n';

    return 0;
} 