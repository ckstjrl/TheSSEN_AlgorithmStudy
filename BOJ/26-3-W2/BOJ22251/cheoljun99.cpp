/*
    solved(BOJ22251 / G5): 빌런 호석
    
    구현
*/

#include <bits/stdc++.h>
using namespace std;

// 0~9까지의 LED 점등 상태 (7개 칸)
int digit[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

int dist[10][10]; // 숫자 i에서 j로 바꿀 때 반전 횟수
int N, K, P, X;

// 숫자를 K자리의 배열로 변환 (ex: 5 -> {0, 0, 5} if K=3)
vector<int> to_digit_vec(int num) {
    vector<int> v(K);
    for (int i = K - 1; i >= 0; i--) {
        v[i] = num % 10;
        num /= 10;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> P >> X;

    // 숫자 간 반전 비용 미리 계산
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int diff = 0;
            for (int h = 0; h < 7; h++) {
                if (digit[i][h] != digit[j][h]) diff++;
            }
            dist[i][j] = diff;
        }
    }

    int ans = 0;
    vector<int> origin = to_digit_vec(X);

    // 1층부터 N층까지 확인
    for (int i = 1; i <= N; i++) {
        if (i == X) continue; // 현재 층은 제외

        vector<int> target = to_digit_vec(i);
        int total_diff = 0;

        for (int j = 0; j < K; j++) {
            total_diff += dist[origin[j]][target[j]];
        }

        // 조건 만족 시 카운트 (최소 1개, 최대 P개)
        if (total_diff <= P) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}