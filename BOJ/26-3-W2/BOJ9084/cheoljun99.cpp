/*
solved(BOJ9084 / G5): 동전
점화식: dp[j] = dp[j] + dp[j - coin]
j원을 만드는 방법 = (기존 방법) + (현재 동전을 하나 써서 j원을 만드는 방법)

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m, coins[21], dp[10005] = {1, }; // dp[0] = 1 초기화
        
        cin >> n;
        for (int i = 0; i < n; i++) cin >> coins[i];
        cin >> m;

        // 점화식: dp[j] = dp[j] + dp[j - coin]
        // j원을 만드는 방법 = (기존 방법) + (현재 동전을 하나 써서 j원을 만드는 방법)
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= m; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[m] << "\n";
    }
}