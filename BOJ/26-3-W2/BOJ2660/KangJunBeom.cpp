#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int N;

int get_score(int start) {
    int dist[51];
    fill(dist, dist + 51, -1);

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int max_dist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (dist[next] != -1) continue;

            dist[next] = dist[curr] + 1;
            max_dist = max(max_dist, dist[next]);
            q.push(next);
        }
    }
    return max_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> scores(N + 1);
    int min_score = 1e9;

    for (int i = 1; i <= N; i++) {
        scores[i] = get_score(i);
        min_score = min(min_score, scores[i]);
    }

    vector<int> candidates;
    for (int i = 1; i <= N; i++) {
        if (scores[i] == min_score) {
            candidates.push_back(i);
        }
    }

    cout << min_score << " " << candidates.size() << "\n";
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i] << (i == candidates.size() - 1 ? "" : " ");
    }

    return 0;
}