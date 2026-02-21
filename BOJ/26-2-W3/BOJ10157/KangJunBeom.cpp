#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, R, K;
    cin >> C >> R >> K;

    if (K > C * R) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> visited(C + 1, vector<int>(R + 1, 0));

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 1, y = 1;
    int dir = 0;

    for (int i = 1; i <= K; ++i) {
        visited[x][y] = i;

        if (i == K) {
            cout << x << " " << y;
            return 0;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 1 || nx > C || ny < 1 || ny > R || visited[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    return 0;
}