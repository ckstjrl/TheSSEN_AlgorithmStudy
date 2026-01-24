# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;  
  
vector<int>graph[101];
int dist[101];

int BFS(int start, int target)
{
    queue<int>q;  
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(target == curr) return dist[curr];

        for(int i=0; i<graph[curr].size(); i++)
        {   
            int next = graph[curr][i];
            if(dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);

            }

        }
    }
    
    return -1;
}


int main(){
    int N, start, target, M;
    cin >> N >> start >> target >> M;

    for (int i=0; i<M; i++)
    {
        int r, c;
        cin >> r >> c;
        graph[r].push_back(c);
        graph[c].push_back(r);
    }

    for (int i=0; i<101; i++)
    {
        dist[i] = -1;
    }

    cout << BFS(start, target) << "\n";


    return 0;
}