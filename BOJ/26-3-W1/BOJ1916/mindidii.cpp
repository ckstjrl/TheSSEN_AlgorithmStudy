#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int INF = 1e9;
vector<pair<int, int>>graph[1001];
vector<int>visit;

int dijkstra(int start, int end)
{

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
    pq.push({start, 0});
    visit.assign(N+1,INF);
    visit[start] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().first;
        int curr_d = pq.top().second;
        pq.pop();

        if (visit[curr] < curr_d) continue;

        for(auto& edge: graph[curr])
        {
            int nxt = edge.first;
            int d = edge.second;

            if(visit[nxt] <= curr_d + d) continue;
            
            visit[nxt] = curr_d + d;
            pq.push({nxt, visit[nxt]});

        }
    }

    return visit[end];
    
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b, weight;
    for(int i=0; i<M; i++)
    {
        cin >> a >> b >> weight;
        graph[a].push_back({b, weight});
    }

    int s, e;
    cin >> s >> e;
    cout << dijkstra(s, e) << "\n";

    return 0;
}