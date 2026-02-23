// solved(BOJ11660 / S1): 구간 합 구하기 5

#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<vector<int>>table(N, vector<int>(N, 0));
	vector<vector<int>>dp(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int num;
			cin >> num;
			table[i][j] = num;
		}
	}
	dp[0][0] = table[0][0];
	for (int i = 1; i < N; ++i) {
		dp[0][i] = dp[0][i - 1] + table[0][i];
		dp[i][0] = dp[i-1][0] + table[i][0];
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + table[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 -= 1;
		y1 -= 1;
		x2 -= 1;
		y2 -= 1;
		int sum = dp[x2][y2];
		if (x1 > 0) sum -= dp[x1 - 1][y2];
		if (y1 > 0) sum -= dp[x2][y1 - 1];
		if (x1 > 0 && y1 > 0) sum += dp[x1 - 1][y1 - 1];
		cout << sum << '\n';
	}
	return 0;
}