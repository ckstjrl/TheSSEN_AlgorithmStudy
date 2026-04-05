#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<string>map_normal(N, "");
    vector<string>map_abnormal(N, "");
    vector<vector<bool>>visted_normal(N, vector<bool>(N, false));
    vector<vector<bool>>visted_abnormal(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        cin >> map_normal[i];
        for (int j = 0; j < N; ++j) {
            if (map_normal[i][j] == 'G') {
                map_abnormal[i] += 'R';
            }
            else {
                map_abnormal[i] += map_normal[i][j];
            }
        }
    }
    int res1 = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visted_normal[i][j] == true)
                continue;
            else {
                res1++;
                queue<tuple<int,int,char>>q;
                int x_dir[4] = { 1,-1,0,0 };
                int y_dir[4] = { 0,0,1,-1 };
                q.push({ i,j,map_normal[i][j] });
                visted_normal[i][j] = true;
                while (!q.empty()) {
                    int x_cur = get<0>(q.front());
                    int y_cur = get<1>(q.front());
                    char ch_chk = get<2>(q.front());
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x_next = x_cur + x_dir[k];
                        int y_next = y_cur + y_dir[k];
                        if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N)
                            continue;
                        if (map_normal[x_next][y_next] != ch_chk)
                            continue;
                        if (visted_normal[x_next][y_next] == true)
                            continue;
                        q.push({ x_next,y_next,ch_chk });
                        visted_normal[x_next][y_next] = true;
                    }
                }
            }
        }
    }
    int res2 = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visted_abnormal[i][j] == true)
                continue;
            else {
                res2++;
                queue<tuple<int, int, char>>q;
                int x_dir[4] = { 1,-1,0,0 };
                int y_dir[4] = { 0,0,1,-1 };
                q.push({ i,j,map_abnormal[i][j] });
                visted_abnormal[i][j] = true;
                while (!q.empty()) {
                    int x_cur = get<0>(q.front());
                    int y_cur = get<1>(q.front());
                    char ch_chk = get<2>(q.front());
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x_next = x_cur + x_dir[k];
                        int y_next = y_cur + y_dir[k];
                        if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N)
                            continue;
                        if (map_abnormal[x_next][y_next] != ch_chk)
                            continue;
                        if (visted_abnormal[x_next][y_next] == true)
                            continue;
                        q.push({ x_next,y_next,ch_chk });
                        visted_abnormal[x_next][y_next] = true;
                    }
                }
            }
        }
    }
    cout << res1 <<' ' << res2;
    return 0;
}
