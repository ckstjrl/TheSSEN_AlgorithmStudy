/*
BOJ 2178 미로 탐색 Silver 1
bfs 사용 + 가지치기 사용 + 각 위치의 최소 가중치를 저장할 2차원 배열 사용
*/
#include <bits/stdc++.h>

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector <vector<int>> min(N, vector<int>(M, -1));
	vector<vector<int>> miro(N, vector<int>(M,0));
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j) {
			miro[i][j] = str[j] - '0';
		}
	}
	int dir_x[4] = { 0,0,1,-1 };
	int dir_y[4] = { 1,-1,0,0 };
	queue<tuple<int, int,int>> q;
	q.push({0,0,1});
	while (!q.empty()) {
		int cur_x = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cur_deep = get<2>(q.front());
		q.pop();
		if (min[cur_x][cur_y] == -1) min[cur_x][cur_y] = cur_deep;
		else if (min[cur_x][cur_y] <= cur_deep) continue;
		else if (min[cur_x][cur_y] > cur_deep) min[cur_x][cur_y] = cur_deep;
		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir_x[i];
			int next_y = cur_y + dir_y[i];
			int next_deep = cur_deep + 1;
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (miro[next_x][next_y] == 1) q.push({ next_x,next_y,next_deep });
			}
		}
	}
	cout << min[N-1][M-1];
	return 0;
}