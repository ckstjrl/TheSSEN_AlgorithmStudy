/*

solved(BOJ13549 / S5): 숨바꼭질 3

다익스트라를 사용하다.

*/

#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> Dijkstra_list(100001, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0,N });
	Dijkstra_list[N] = 0;
	while (!q.empty()) {
		int cur_idx = q.top().second;
		int cur_deep = q.top().first;
		q.pop();
		if (cur_deep != Dijkstra_list[cur_idx]) {
			continue;
		}
		for (int i = 0; i < 3; ++i) {
			int next_idx;
			int next_deep = cur_deep + 1;
			if (i == 0) {
				next_idx = cur_idx - 1;
			}
			else if (i == 1) {
				next_idx = cur_idx + 1;
			}
			else {
				next_idx = cur_idx * 2;
				next_deep = cur_deep;
			}
			if (next_idx <= 100000 && next_idx >= 0) {
				if (next_deep < Dijkstra_list[next_idx]) {
					q.push({next_deep,next_idx });
					Dijkstra_list[next_idx] = next_deep;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
	}
	cout << Dijkstra_list[K];
	return 0;
}