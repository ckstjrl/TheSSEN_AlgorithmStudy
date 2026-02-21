// ABCDE
# include <iostream>
# include <vector>

using namespace std;

int N, M;
bool found;
vector<int>friends[2001];
vector<int>visit;

void dfs(int start, int depth)
{
    cout << start << ' ';
    if(depth == 4)
    {
        found = true;
        return;
    }

    for(int i=0; i<friends[start].size(); i++)
    {
        int nxt = friends[start][i];
        if(visit[nxt] == 0)
        {
            visit[nxt] = 1;
            dfs(nxt, depth+1);
            visit[nxt] = 0;

            if(found) return; 
        }
    
    }

}

int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for(int i=0; i<=N; i++)
    {
        visit.assign(N+1, 0);
        visit[i] = 1;
        dfs(i, 0);
        cout << "\n";
    }

    if(found) cout << 1;
    else cout << 0;

    return 0;
}