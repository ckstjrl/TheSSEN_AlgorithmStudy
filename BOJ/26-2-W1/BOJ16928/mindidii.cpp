#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int>board;
vector<int>visit;

void bfs()
{
    queue<int>q;
    q.push(1);
    visit[1] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i=1; i<7; i++)
        {
            int next = curr + i;
            if(next < 101)
            {
                
                if(board[next] != 0)
                {   
                    next = board[next];
                    
                }
                if(visit[next] == -1)
                {
                    visit[next] = visit[curr] + 1;
                    q.push(next);
                }
                
            }
        }
    }
    


}

int main(){
    
    board.assign(101, 0);
    visit.assign(101, -1);
    cin >> N >> M;
    for(int i=0; i<N+M; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    bfs();

    cout << visit[100] << '\n';


    return 0;
}