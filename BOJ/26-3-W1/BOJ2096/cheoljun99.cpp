/*

solved(BOJ2096 / S5): 내려가기

이전 위치에 따른 가능한 현재 위치가 각각 두개씩 생기므로 DP를 사용할 수 있음
입력 범위가 매우 커서 일반적인 DP 보다는 pre DP와 cur DP만 사용해서 구할 수 있음

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    // 현재 줄의 결과와 이전 줄의 결과를 저장할 배열
    int curMaxDp[3], curMinDp[3];
    int prevMaxDp[3], prevMinDp[3];
    // 첫 번째 줄 입력 및 초기화
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        prevMaxDp[i] = prevMinDp[i] = num;
    }
    // 두 번째 줄부터 N번째 줄까지
    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c; // Cur 줄의 숫자 3개
        // 최대값 갱신
        curMaxDp[0] = a + max(prevMaxDp[0], prevMaxDp[1]);
        curMaxDp[1] = b + max({prevMaxDp[0], prevMaxDp[1], prevMaxDp[2]});
        curMaxDp[2] = c + max(prevMaxDp[1], prevMaxDp[2]);
        // 최소값 갱신
        curMinDp[0] = a + min(prevMinDp[0], prevMinDp[1]);
        curMinDp[1] = b + min({prevMinDp[0], prevMinDp[1], prevMinDp[2]});
        curMinDp[2] = c + min(prevMinDp[1], prevMinDp[2]);
        // 다음 줄 계산을 위해 현재 값을 prev에 복사
        for (int j = 0; j < 3; j++) {
            prevMaxDp[j] = curMaxDp[j];
            prevMinDp[j] = curMinDp[j];
        }
    }
    cout << max({prevMaxDp[0], prevMaxDp[1], prevMaxDp[2]}) << " ";
    cout << min({prevMinDp[0], prevMinDp[1], prevMinDp[2]}) << endl;
    return 0;
}