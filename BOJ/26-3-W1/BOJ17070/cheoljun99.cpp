/*

solved(BOJ17070 / S5): 파이프 옮기기 1

DP를 사용
1. 가로 방향으로 도착하는 경우
머리(i, j)와 꼬리(i, j-1)가 모두 빈 칸이어야 함
이전 상태는 가로(0)였거나 대각선(2)일때 가능
2. 세로 방향으로 도착하는 경우
머리(i, j)와 꼬리(i-1, j)가 모두 빈 칸이어야 함
이전 상태는 세로(1)였거나 대각선(2)일때 가능
3. 대각선 방향으로 도착하는 경우
머리(i, j), 꼬리(i-1, j-1), 그리고 옆구리(i-1, j), (i, j-1) 총 4칸이 빈 칸이어야
이전 상태는 가로(0), 세로(1), 대각선(2) 일때 모두 가능

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0)); // 벽 저장 테이블
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> table[i][j];
        }
    }
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3, 0)));
    // 0 = 가로 1 = 세로 2 = 대각선
    dp[1][2][0] = 1; // 초기값 세팅
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == 1 && j == 2) continue; //초기값인 경우 건너뜀
            // 1. 가로 방향으로 도착하는 경우
            // 머리(i, j)와 꼬리(i, j-1)가 모두 빈 칸이어야 함
            if (j - 1 >= 1 && table[i][j] == 0 && table[i][j - 1] == 0) {
                // 이전 상태는 가로(0)였거나 대각선(2)일때 가능
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            }
            // 2. 세로 방향으로 도착하는 경우
            // 머리(i, j)와 꼬리(i-1, j)가 모두 빈 칸이어야 함
            if (i - 1 >= 1 && table[i][j] == 0 && table[i - 1][j] == 0) {
                // 이전 상태는 세로(1)였거나 대각선(2)일때 가능
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            }
            // 3. 대각선 방향으로 도착하는 경우
            if (i - 1 >= 1 && j - 1 >= 1) {
                if (table[i][j] == 0 && table[i - 1][j - 1] == 0 && table[i - 1][j] == 0 && table[i][j - 1] == 0) {
                    // 머리(i, j), 꼬리(i-1, j-1), 그리고 옆구리(i-1, j), (i, j-1) 총 4칸이 빈 칸이어야
                    // 이전 상태는 가로(0), 세로(1), 대각선(2) 일때 모두 가능
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
            }
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << "\n";
    return 0;
}
