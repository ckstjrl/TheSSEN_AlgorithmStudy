#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> shoelace(N+1, {0,0}); // x,y;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        shoelace[i].first = x;
        shoelace[i].second = y;
    }
    shoelace[N].first = shoelace[0].first;
    shoelace[N].second = shoelace[0].second;
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        total += (long long)shoelace[i].first * shoelace[i + 1].second;
        total -= (long long)shoelace[i].second * shoelace[i + 1].first;
    }
    printf("%.1f\n", abs(total) / 2.0);
    return 0;
}