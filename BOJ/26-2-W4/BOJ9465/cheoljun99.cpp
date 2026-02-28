// solved(BOJ9465 / S1): 스티커

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<vector<int>>table(2, vector<int>(N, 0));
		vector<vector<int>>dp(2, vector<int>(N, 0));
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < N; ++k) {
				int num;
				cin >> num;
				table[j][k] = num;
			}
		}
		dp[0][0] = table[0][0];
		dp[0][1] = table[1][0] + table[0][1];
		dp[1][0] = table[1][0];
		dp[1][1] = table[0][0] + table[1][1];
		for (int j = 2; j < N; ++j) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + table[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + table[1][j];
		}
		int res = 0;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < N; ++k) {
				if (res < dp[j][k]) {
					res = dp[j][k];
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}