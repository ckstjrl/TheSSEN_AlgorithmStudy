/*
solved(BOJ2660 / G5): 회장뽑기

A일때 B C D 의 점수를 구하고 최대값이 A의 점수
B일때 A C D 의 점수를 구하고 최대값이 B의 점수
관계가 A - B - C (A와 B가 친구, B와 C가 친구)라면:
A가 출발점: B까지 1단계, C까지 2단계 → A의 점수는 2점 (최댓값)
B가 출발점: A까지 1단계, C까지 1단계 → B의 점수는 1점 (최댓값)
C가 출발점: B까지 1단계, A까지 2단계 → C의 점수는 2점 (최댓값)

*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dist[55][55];
int score[55];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int u, v;
    while (cin >> u >> v && (u != -1 && v != -1)) {
        dist[u][v] = dist[v][u] = 1;
    }
    // 플루이드 와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 각 회원의 점수 계산 (다른 회원과의 거리 중 최댓값)
    int min_score = INF;
    for (int i = 1; i <= n; i++) {
        int max_dist = 0;
        for (int j = 1; j <= n; j++) {
            max_dist = max(max_dist, dist[i][j]);
        }
        score[i] = max_dist;
        min_score = min(min_score, score[i]);
    }

    // 회장 후보 찾기
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        if (score[i] == min_score) {
            candidates.push_back(i);
        }
    }

    cout << min_score << " " << candidates.size() << "\n";
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i] << (i == candidates.size() - 1 ? "" : " ");
    }

    return 0;
}