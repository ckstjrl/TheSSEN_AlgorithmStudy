// 파스칼의 삼각형 

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main()
{

    int n,k;
    cin >> n >> k;
    int dp[31][31];
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;

    for(int r=3; r<=n; r++)
    {
        dp[r][0] = 1;
        dp[r][r] = 1;
        for(int c=1; c<r-1; c++)
        {
            dp[r][c] = dp[r-1][c-1] + dp[r-1][c];
        }
    }

    cout << dp[n][k-1];



    return 0;
}