// solved(BOJ30804/ S2): 과일 탕후루
// 슬라이딩 윈도우

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    int left = 0, right = 0;
    int ans = 0;
    int type_cnt = 0;
    unordered_map<int, int>un_map;
    for (int right = 0; right < N; ++right) {
        if (un_map[vec[right]] == 0)
            type_cnt++;
        un_map[vec[right]]++;
        while (type_cnt > 2) {
            un_map[vec[left]]--;
            if (un_map[vec[left]] == 0)
                type_cnt--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << ans;
    return 0;
}
