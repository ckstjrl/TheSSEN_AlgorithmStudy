//solved(BOJ14940/ S1): 쉬운 최단거리

#include <bits/stdc++.h>

using namespace std;

void printTable(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); ++i) {
		for (int j = 0; j < table[0].size(); ++j) {
			cout << table[i][j];
			cout << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>table(N, vector<int>(M, 0));
	vector<vector<int>>vistied(N, vector<int>(M, -1));
	int x_dir[4] = { 1,-1,0,0 };
	int y_dir[4] = { 0,0,1,-1 };
	int x_start = 0;
	int y_start = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int num;
			cin >> num;
			table[i][j] = num;
			if (num == 0) {
				vistied[i][j] = 0;
			}
			if (num == 2) {
				x_start = i;
				y_start = j;
				vistied[i][j] = 0;
			}
		}
	}
	queue<tuple<int, int,int>> q;
	q.push({x_start,y_start,0});
	while (!q.empty()) {
		int x_cur = get<0>(q.front());
		int y_cur = get<1>(q.front());
		int idx_cur =get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x_next = x_cur + x_dir[i];
			int y_next = y_cur + y_dir[i];
			int idx_next = idx_cur + 1;
			if (x_next >= N || y_next >= M || x_next < 0 || y_next < 0)
				continue;
			if (table[x_next][y_next] == 0)
				continue;
			if (vistied[x_next][y_next] != -1 && vistied[x_next][y_next] <= idx_next)
				continue;
			vistied[x_next][y_next] = idx_next;
			q.push({ x_next,y_next ,idx_next });
		}
	}
	printTable(vistied);
}