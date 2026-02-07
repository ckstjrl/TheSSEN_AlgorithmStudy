#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dist[101][101];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_score = INF;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) sum += dist[i][j];

        if (sum < min_score) {
            min_score = sum;
            ans = i;
        }
    }

    cout << ans;
    return 0;
}