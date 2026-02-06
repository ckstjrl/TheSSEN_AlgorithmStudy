#include <bits/stdc++.h>
using namespace std;

int board[101];
int dist[101];

void bfs() {
    fill(dist, dist + 101, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next > 100) continue;

            if (board[next] != 0) {
                next = board[next];
            }

            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    bfs();
    cout << dist[100];
    return 0;
}