#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;

long long dp[17][17][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    map.resize(N, vector<int>(N));
    for(int r=0; r<N; r++)
        for(int c=0; c<N; c++)
            cin >> map[r][c];

    dp[0][1][0] = 1;

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            if(map[r][c] == 1) continue;

            if(dp[r][c][0])
            {
                if(c+1 < N && map[r][c+1] == 0)
                    dp[r][c+1][0] += dp[r][c][0];

                if(r+1 < N && c+1 < N &&
                   map[r][c+1] == 0 &&
                   map[r+1][c] == 0 &&
                   map[r+1][c+1] == 0)
                    dp[r+1][c+1][2] += dp[r][c][0];
            }

            if(dp[r][c][1])
            {
                if(r+1 < N && map[r+1][c] == 0)
                    dp[r+1][c][1] += dp[r][c][1];

                if(r+1 < N && c+1 < N &&
                   map[r][c+1] == 0 &&
                   map[r+1][c] == 0 &&
                   map[r+1][c+1] == 0)
                    dp[r+1][c+1][2] += dp[r][c][1];
            }

            if(dp[r][c][2])
            {
                if(c+1 < N && map[r][c+1] == 0)
                    dp[r][c+1][0] += dp[r][c][2];

                if(r+1 < N && map[r+1][c] == 0)
                    dp[r+1][c][1] += dp[r][c][2];

                if(r+1 < N && c+1 < N && map[r][c+1] == 0 && map[r+1][c] == 0 && map[r+1][c+1] == 0)
                    dp[r+1][c+1][2] += dp[r][c][2];
            }
        }
    }

    cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2];

    return 0;
}