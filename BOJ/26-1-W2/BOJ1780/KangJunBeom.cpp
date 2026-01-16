#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int result[3];

void solve(int r, int c, int n) {
    int current_val = paper[r][c];
    bool is_uniform = true;

    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (paper[i][j] != current_val) {
                is_uniform = false;
                break;
            }
        }
        if (!is_uniform) break;
    }

    if (is_uniform) {
        result[current_val + 1]++;
    } else {
        int next_n = n / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                solve(r + i * next_n, c + j * next_n, next_n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}