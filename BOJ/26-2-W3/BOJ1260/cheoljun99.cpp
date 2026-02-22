//solved(BOJ1260/ S2): DFS와 BFS

#include<bits/stdc++.h>

using namespace std;


int arr[1001][1001];
int visited[1001];
int N, M, V;

void DFS(int V) {
	visited[V] = 1;
	cout << V << " ";
	for (int i = 1; i <= N; i++) {
		if (arr[V][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
	}
}
void BFS(int V) {
	queue<int>q;
	q.push(V);
	visited[V] = 1;
	cout << V << " ";

	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[next][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> V;

	int u, v;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1; //간선이 양뱡향이기 때문에 u,v <-> v,u 를 해줌
	}
	
	DFS(V);
	cout << '\n';
	memset(visited, 0, sizeof(visited));
	BFS(V);

}