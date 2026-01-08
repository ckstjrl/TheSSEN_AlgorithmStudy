/*
BOJ 18111 Four 마인크래프트 Silver 2

3중 for문 부르트포스

256 * 500 * 500 = 64,000,000

*/

#include <bits/stdc++.h>

using namespace std;
int main() {
	int N,M,B;
	cin >> N >> M >> B;
	vector<vector<int>>map(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	int answer = -1;
	int high = -1;
	for (int i = 0; i <= 256; ++i) {
		int total_need = 0;
		int total_erase = 0;
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < M; ++y) {
				if (i < map[x][y]) {
					total_erase += (map[x][y] - i);
				}
				else if (i > map[x][y]) {
					total_need += (i - map[x][y]);
				}
			}
		}
		int temp = total_need - B;
		if (temp == 0) {
			if (answer == -1) {
				answer = B + (2 * total_erase);
				high = i;
			}
			else if (answer >= (B + (2 * total_erase))) {
				answer = B + (2 * total_erase);
				high = i;
			}
		}
		else if (temp < 0) {
			if (answer == -1) {
				answer = B + temp + (2 * total_erase);
				high = i;
			}
			else if (answer >= (B + temp + (2 * total_erase))) {
				answer = B + temp + (2 * total_erase);
				high = i;
			}
		}
		else if (temp > 0) {
			if (total_erase >= temp) {
				if (answer == -1) {
					answer = B + temp + (2 * total_erase);
					high = i;
				}
				else if (answer >= (B + temp + (2 * total_erase))) {
					answer = B + temp + (2 * total_erase);
					high = i;
				}
			}
		}
	}
	cout << answer<<" "<<high;
	return 0;
}