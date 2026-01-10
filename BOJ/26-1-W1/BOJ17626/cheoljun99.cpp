/*
BOJ 17626 Four Squares Silver 3

일반화 하는 방법
dp[0] = 0
dp[1] = 1;
dp[2] = dp[1]+1 or 2이하의 제곱근 x가, 하나 이상 있다 가정하고 그 값을 뺀 dp[1-x] + 1;
dp[3] = dp[2]+1; or 3이하의 제곱근 x가, 하나 이상 있다 가정하고 그 값을 뺀 dp[1-x] + 1;
dp[4] = dp[3]+1 or 4이하의 제곱근 x가, 하나 이상 있다 가정하고 그 값을 뺀 dp[1-x] + 1;
...
dp[n] = dp[n-1]+1 or N이하의 제곱근 x가, 하나 이상 있다 가정하고 그 값을 뺀 dp[1-x] +1;

sudo

first step

dp[N] = for(i : N이하의 제곱근 목록) min(dp[N-1]+1, dp[N-i*i]+1)

next step
dp[N] = for(i:N이하의 제곱근 목록) min(dp[N],dp[N-i*i]+1)


*/

#include <bits/stdc++.h>

using namespace std;
int main() {
	
	int n;
	cin >> n;

	vector<int> dp(n+3,0);
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	cout << dp[n];
	return 0;
}