// 구간 합 구하기 

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int N, M;
vector<vector<int>>map;
vector<vector<int>>prefix;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    map.assign(N+2, vector<int>(N+2, 0));
    prefix.assign(N+2, vector<int>(N+2, 0));

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int a;
            cin >> a;
            map[i][j] = a;
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + map[i][j] - prefix[i-1][j-1];
        }
    }

    for(int i=0; i<M; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int curr_sum = prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1];
        cout << curr_sum << '\n';

    }


    return 0;
}