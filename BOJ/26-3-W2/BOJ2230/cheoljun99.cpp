/*
solved(BOJ2230 / G5): 수 고르기

투포인터를 활용한다.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int en = 0;
    long long min_diff = 2e9 + 7; 
    for (int st = 0; st < n; st++) {
        // 두 수의 차이가 m 이상이 될 때까지 en 포인터를 이동
        while (en < n && a[en] - a[st] < m) {
            en++;
        }
        // en이 배열 끝을 벗어났다면 st를 더 키워도 m 이상인 차이를 찾을 수 없음
        if (en == n) break;
        // 현재 차이(a[en] - a[st])와 기존 최솟값을 비교하여 갱신
        min_diff = min(min_diff, a[en] - a[st]);
        // 만약 차이가 정확히 m이라면 이보다 더 작은 m 이상의 차이는 없으므로 즉시 종료
        if (min_diff == m) break;
    }
    cout << min_diff;
    return 0;
}