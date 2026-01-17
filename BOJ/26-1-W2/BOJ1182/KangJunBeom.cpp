#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    int cnt = 0;

    for (int i = 1; i < (1 << n); i++) { // 조합의 경우의 수 총 개수 2^n 승 만큼
        long long sum = 0;
        
        for (int j = 0; j < n; j++) { // 전체 수열 개수 중 선택되는 애들만 더하기
            if (i & (1 << j)) { // 1<<j 는 해당 번호가 입력할 데이터인지 체크하기 위한 값
                sum += num[j];
            }
        }

        if (sum == s) cnt++;
    }

    cout << cnt;
    return 0;
}