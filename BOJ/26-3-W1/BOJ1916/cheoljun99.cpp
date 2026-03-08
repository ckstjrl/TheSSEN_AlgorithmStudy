

#include<bits/stdc++.h>

using namespace std;

/*

solved(BOJ1916 / S5): 최소비용 구하기

다익스트라에서 간선은 인접 리스트 -> 간선을 저장할 자료구조
시간복잡도는 O(V^2+E)
다익스트라에서 최소 거리(출발점(고정)에서 도착점(유동)까지)는 일차원 리스트 -> 최소 거리(dist)를 저장할 자료구조
fix는 일차원 배열 
최소 dist 선택 -> fix -> 인접 간선 relax(인접 간선 조사 후 dist 배열 갱신) -> 이걸 V번(정점 수) 반복

최소 dist 선택 -> 시간복잡도 O(V)
인접 간선 조사 -> 직관적으로 볼때 O(E/V)
위 두개를 O(V)번 반복

전체 시간 복잡도 O(V^2+E)

하지만 최대한 효율적으로 우선순위 큐를 사용 O(VlogE)

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> list(N,vector<pair<int,int>>());
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a -= 1;
		b -= 1;

		list[a].push_back({ b,c });
	}
	int start;
	int stop;
	cin >> start >> stop;
	start -= 1;
	stop -= 1;
	vector<int> table(N,INT_MAX);
	priority_queue<pair<int, int>>q;
	q.push({ start,0 });
	table[start] = 0;
	while (!q.empty()) {
		int cur_idx = q.top().first;
		int cur_dist = q.top().second;
		q.pop();
		if (cur_dist != table[cur_idx]) {
			continue;
		}
		for (int i = 0; i < list[cur_idx].size(); ++i) {
			int next_idx = list[cur_idx][i].first;
			int next_dist = cur_dist + list[cur_idx][i].second;
			if (next_dist >= table[next_idx])
				continue;
			q.push({ next_idx,next_dist });
			table[next_idx] = next_dist;
		}
	}
	cout << table[stop];
	return 0;
}