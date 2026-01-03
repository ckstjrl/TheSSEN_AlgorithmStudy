#include <bits/stdc++.h>
using namespace std;

int num;

int solve(int n) {
    if (n <= 1) return 0;

    int res = solve(n / 3) + (n % 3) + 1;
    res = min(res, solve(n / 2) + (n % 2) + 1);

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> num;
    cout << solve(num);

    return 0;
}