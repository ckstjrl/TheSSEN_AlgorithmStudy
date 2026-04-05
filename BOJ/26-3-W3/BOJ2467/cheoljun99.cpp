#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> list(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> list[i];
    }
    int left = 0;
    int right = N - 1;

    int res = INT_MAX;
    int res_left = 0;
    int res_right = 0;
    while (left != right) {
        int temp = list[left] + list[right];
        if (res >  abs(0 - temp)) {
            res_left = list[left];
            res_right = list[right];
            res = abs(temp);
        }
        if (temp >= 0) {
            --right;
        }
        else {
            ++left;
        }
    }
    cout << res_left<<" "<<res_right;
    return 0;
}