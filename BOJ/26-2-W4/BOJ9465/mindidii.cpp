# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int T, n;
int sticker[2][100001];
long long dp[3][100001];

int main()
{
    cin >> T;
    int a;
    
    while (T--)
    {
        cin >> n;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> a;
                sticker[i][j] = a;
            }
        }

        dp[1][0] = sticker[0][0];
        dp[2][0] = sticker[1][0];
        long long max_val = max({dp[0][0], dp[1][0],dp[2][0]});
        
        for(int i=1; i<n; i++)
        {
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]);
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + sticker[0][i];
            dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + sticker[1][i];
            max_val = max({dp[0][i], dp[1][i], dp[2][i], max_val});
        }

        cout << max_val << '\n';
    }
    

    return 0;
}