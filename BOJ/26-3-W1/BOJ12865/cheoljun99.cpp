/*

solved(BOJ12865 / S5): 평범한 배낭

2차원 DP 배열을 두고
행은 준서가 버틸 수 있는 무게(1~K)이다.
열은 물건 종류이다.
이때 열이 하나 씩 증가한다는 증가한 열 바로 왼쪽 이전 열이 이전 시점의 최대 상태인 시점을 보장하고 그 최대 상태에서 넣을 최신 물건이라는 것
즉 DP의 점화식을 구할 수 있다.

for (int i = 1; i < N; ++i) {
    for (int j =1; j <= K; ++j) {
        if (j >= vec[i].first)
            dp[j][i] = max(dp[j][i - 1], dp[j - vec[i].first][i - 1] + vec[i].second);
        else
            dp[j][i] = dp[j][i - 1];
    }
}

물건을 넣는 순간에 넣을 수 있다면 남는 공간 만큼 직전에 넣어 둔 값 + 넣는 값  VS 이전 열의 값
최대를 갱신

*/

#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int K;
	cin >> N >> K;
	vector<pair<int, int>> vec;
	for (int i = 0; i < N; ++i) {
		int W, V;
		cin >> W >> V;
		vec.push_back({ W,V });
	}
	vector<vector<int>> dp(K+1, vector<int>(N, 0));
	for (int i = 0; i <= K; ++i) {
		if (i >= vec[0].first) {
			dp[i][0] = vec[0].second;
		}
	}
	for (int i = 1; i < N; ++i) {
		dp[0][i] =0;
	}
	for (int i = 1; i < N; ++i) {
		for (int j =1; j <= K; ++j) {
			if (j >= vec[i].first)
				dp[j][i] = max(dp[j][i - 1], dp[j - vec[i].first][i - 1] + vec[i].second);
			else
				dp[j][i] = dp[j][i - 1];
		}
	}
	int res = 0;
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j < N; ++j) {
			if (res < dp[i][j]) {
				res = dp[i][j];
			}
		}
	}
	cout << res;
	return 0;
}