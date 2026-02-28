// solved(BOJ10917 / S2): Your life
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>>list(N, vector<int>());
    vector<bool> visited(N, false);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        list[x - 1].push_back(y - 1);
    }
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0] = true;
    while (!q.empty()) {
        int cur_idx = q.front().first;
        int cur_deep = q.front().second;
        q.pop();
        for (int i = 0; i < list[cur_idx].size(); ++i) {
            int next_idx = list[cur_idx][i];
            int next_deep = cur_deep + 1;
            if (visited[next_idx] == true)
                continue;
            else {
                if (next_idx == N -1) {
                    cout << next_deep;
                    return 0;
                }
                else {
                    q.push({ next_idx,next_deep });
                    visited[list[cur_idx][i]] = true;
                }
            }
        }
    }
    cout << -1;
    return 0;
}