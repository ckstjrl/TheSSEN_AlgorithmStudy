// solved(BOJ1149 / S1): RGB거리
// DP 사용

#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>>vec(N,vector<int>(3,0));
	vector<vector<int>>DP(N, vector<int>(3,0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vec[i][j];
		}
	}
	DP[0][0] = vec[0][0];
	DP[0][1] = vec[0][1];
	DP[0][2] = vec[0][2];

	for (int i = 1; i < N; i++) {
		DP[i][0] = min(DP[i - 1][1] + vec[i][0], DP[i - 1][2] + vec[i][0]);
		DP[i][1] = min(DP[i - 1][0] + vec[i][1], DP[i - 1][2] + vec[i][1]);
		DP[i][2] = min(DP[i - 1][0] + vec[i][2], DP[i - 1][1] + vec[i][2]);
	}
	cout << min(min(DP[N-1][0], DP[N-1][1]), DP[N-1][2]);
}