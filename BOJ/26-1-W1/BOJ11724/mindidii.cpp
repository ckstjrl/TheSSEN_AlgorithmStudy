// 연결된 요소의 수 
#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int N, M; 
vector<vector<int>> graph(1001); 
vector<int>visited(1001);
queue<int> q;

void BFS(int start)
{
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        int len = graph[curr].size();
        for(int i=0; i<len; i++){
            int b = graph[curr][i];
            if(visited[b] == 0)
            {
                visited[b] = 1;
                q.push(b);
            }    
        }  
    }
}


int main(){
 
    int count = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 인접행렬 출력 
    // for (int i = 1; i < graph.size(); i++) {
    //     cout << i << " : ";
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    
    int start;

    for(int i=1; i<=N; i++)
    {
        if(visited[i] == 0)
        {
            BFS(i);
            count++;
        }
    }

    cout << count;

    return 0;
}