/*
BOJ 11724 연결 요소의 개수 Silver 2

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N, M;
	cin >> N >> M;

	vector<vector<int>>table(N, vector<int>(N, 0));
	vector<int>visited(N, 0);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		table[u - 1][v - 1]=1;
		table[v - 1][u - 1]=1;
	}


	int res = 0;
	for (int i = 0; i < N; i++) {
		queue<int>q;
		if (visited[i] != 1) {
			res++;
			q.push(i);
			visited[i] = 1;
			while (!q.empty()) {
				int next = q.front();
				q.pop();
				for (int i = 0; i < N; i++) {
					if (table[next][i] == 1&&visited[i]==0) {
						q.push(i);
						visited[i] = 1;
					}
				}
			}
		}
	}
	cout << res;


}