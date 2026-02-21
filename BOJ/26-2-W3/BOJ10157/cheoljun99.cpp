//solved(BOJ10157/ S3): 자리배정

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, R;
    cin >> C >> R;
    int K;
    cin >> K;
    if (C * R < K) {
        cout << 0;
        return 0;
    }
    vector<vector<bool>>map(R, vector < bool > (C, false));
    struct state {
        int x, y, dir, idx;
    };
    queue<state> q;
    q.push({ 0,0,0,0 });
    map[0][0]=true;
    while (!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_dir = q.front().dir;
        int cur_idx = q.front().idx;
        q.pop();
        if (cur_idx == K - 1) {
            cout << cur_x+1 << " " << cur_y+1;
            return 0;
        }
        if (cur_dir == 0) {
            int next_x = cur_x;
            int next_y = cur_y + 1;
            int next_dir = cur_dir;
            int next_idx = cur_idx+1;
            if (next_y >= R || map[next_y][next_x]) {
                next_x = cur_x + 1;
                next_y = cur_y;
                next_dir = 1;
            }
            q.push({ next_x ,next_y,next_dir,next_idx });
            map[next_y][next_x] = true;
        }
        else if (cur_dir == 1) {
            int next_x = cur_x+1;
            int next_y = cur_y;
            int next_dir = cur_dir;
            int next_idx = cur_idx + 1;
            if (next_x >= C || map[next_y][next_x]) {
                next_x = cur_x;
                next_y = cur_y-1;
                next_dir = 2;
            }
            q.push({ next_x ,next_y,next_dir,next_idx });
            map[next_y][next_x] = true;
        }
        else if (cur_dir == 2) {
            int next_x = cur_x;
            int next_y = cur_y - 1;
            int next_dir = cur_dir;
            int next_idx = cur_idx + 1;
            if (next_y < 0|| map[next_y][next_x]) {
                next_x = cur_x - 1;
                next_y = cur_y;
                next_dir = 3;
            }
            q.push({ next_x ,next_y,next_dir,next_idx });
            map[next_y][next_x] = true;
        }
        else if (cur_dir == 3) {
            int next_x = cur_x-1;
            int next_y = cur_y;
            int next_dir = cur_dir;
            int next_idx = cur_idx + 1;
            if (next_x < 0 || map[next_y][next_x]) {
                next_x = cur_x;
                next_y = cur_y+1;
                next_dir = 0;
            }
            q.push({ next_x ,next_y,next_dir,next_idx });
            map[next_y][next_x] = true;
        }
    }
    return 0;
}
