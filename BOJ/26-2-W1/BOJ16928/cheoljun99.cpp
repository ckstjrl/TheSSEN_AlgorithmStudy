// solved(BOJ16928/ G5): 뱀과 사다리 게임
// bfs 사용

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N>>M;
	vector<int>table(100, 0);
	vector<bool> visited(100, false);
	for (int i = 0; i < 100; ++i) {
		table[i] = i;
	}
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		table[a-1] = b-1;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		table[a - 1] = b - 1;
	}
	queue<pair<int,int>> q;
	q.push({0,0});
	visited[0] = true;
	int res = 0;
	while (!q.empty()) {
		int cur_idx = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();
		if (cur_idx == 99) {
			res = cur_cnt;
			break;
		}
		else {
			cur_idx = table[cur_idx];
			for (int i = 1; i <= 6; ++i) {
				int next_idx = cur_idx + i;
				if (next_idx > 99) {
					break;
				}
				if (visited[next_idx]) continue;
				visited[next_idx] = true;
				q.push({ next_idx, cur_cnt + 1 });
			}
		}
	}
	cout << res;
	return 0;
}