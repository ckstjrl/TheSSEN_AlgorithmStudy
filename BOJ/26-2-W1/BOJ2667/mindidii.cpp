// 단지 번호 

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int N;
vector<string>danji;
vector<vector<int>>visit;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int r, int c)
{
    int house = 1;
    queue<pair<int, int>>q;
    q.push({r,c});
    visit[r][c] = 1;

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if(visit[nx][ny] == 0 && danji[nx][ny] == '1')
                {
                    visit[nx][ny] = 1;
                    house++;
                    q.push({nx, ny});
                }

            }
        }

    }

    return house;
}

int main()
{
    
    cin >> N;
    cin.ignore();

    string s;
    for(int i=0; i<N; i++)
    {
        if(getline(cin, s))
            danji.push_back(s);
    }

    vector<int>danjiss;
    visit.assign(N, vector<int>(N, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(visit[i][j] == 0 && danji[i][j] == '1')
            {
                int a = bfs(i, j);
                danjiss.push_back(a);
            }
        }
    }

    cout << danjiss.size() << '\n';
    sort(danjiss.begin(), danjiss.end());
    for(int i=0; i<danjiss.size(); i++)
    {
        cout << danjiss[i] << '\n';
    }


    return 0;
}