#if 01
#include <iostream>

using namespace std;

int dp[20][20];
int T; // 테스트케이스 개수

int main()
{
	ios::sync_with_stdio(false);

	cin >> T;

	while(T--)
	{
		int k, n; // k층 n호
		cin >> k >> n;

		for (int i = 1; i <= n; ++i)
		{
			dp[0][i] = i;
		}

		for (int i = 0; i <= k; ++i)
		{
			dp[i][1] = 1;
		}

		for (int i = 1; i <= k; ++i)
		{
			for (int j = 2; j <= n; ++j)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[k][n] << '\n';
	}
	
	return 0;
}

#endif