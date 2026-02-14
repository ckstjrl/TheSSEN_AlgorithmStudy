// solved(BOJ5567/ S2): 결혼식
// bfs

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int M;
    cin >> N >> M;
    vector<vector<int>>list(N,vector<int>());
    vector<bool>visited(N, false);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        list[a-1].push_back(b-1);
        list[b-1].push_back(a-1);
    }
    queue<pair<int, int>>q;
    visited[0] == true;
    q.push({ 0,0 });
    int res = 0;
    while (!q.empty()) {
        int cur_idx = q.front().first;
        int cur_deep = q.front().second;
        q.pop();
        if (cur_deep > 0) {
            res++;
        }
        if (cur_deep == 2) continue;
        for (int i = 0; i < list[cur_idx].size(); ++i) {
            if (visited[list[cur_idx][i]] == false) {
                visited[list[cur_idx][i]] = true;
                q.push({ visited[list[cur_idx][i]],cur_deep+1 });   
            }
        }
    }
    cout << res;
    return 0;
}
