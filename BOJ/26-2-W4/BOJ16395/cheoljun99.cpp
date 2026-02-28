// solved(BOJ16395 / S5): 파스칼의 삼각형

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>>dp(30, vector<int>());
    dp[0].push_back(1);
    for (int i = 1; i < 30; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i].push_back(1);
            }
            else if (j == i) {
                dp[i].push_back(1);
            }
            else {
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
    }
    cout << dp[n - 1][k - 1];
    return 0;
}
