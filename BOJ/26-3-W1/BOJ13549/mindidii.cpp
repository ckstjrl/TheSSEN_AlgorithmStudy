#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
vector<int>visit(100001, -1);

void bfs(int start)
{   
    deque<int>dq;
    dq.push_back(start);
    visit[start] = 0;

    while(!dq.empty())
    {
        int curr = dq.front();
        dq.pop_front();

        int n = curr * 2;
        if(n >= 0 && n <100001)
        {
            if(visit[n] == -1 || visit[n] > visit[curr] + 1)
            {
                visit[n] = visit[curr];
                dq.push_front(n);
            }
            
        }

        int nxt[] = {curr - 1, curr + 1};
        for(int n : nxt)
        {
            if(n >= 0 && n <100001)
            {
                if(visit[n] == -1 || visit[n] > visit[curr] + 1)
                {
                    visit[n] = visit[curr] + 1;
                    dq.push_back(n);
                }
            }
        }
    }

}

int main()
{

    int N, M;
    cin >> N >> M;

    bfs(N);

    cout << visit[M] << '\n';


    return 0;
}