#include <bits/stdc++.h>
using namespace std;  

int n, m, u, v, target;
vector<int> vec[1001];
int visited[1001];

void bfs(const int start){
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while(q.size()){
		int from = q.front();
		q.pop();
		cout << from << ' ';
		for(const int a : vec[from]){
			if(visited[a]) continue;
			q.push(a);
			visited[a] = 1;
		}
	}
}

void dfs(const int start){
	visited[start] = 1;
	cout << start << " ";
	for(const int a : vec[start]){
		if(visited[a]) continue;
		dfs(a);
	}
}

int main(){
	cin >> n >> m >> target;
	for(int i = 0; i<m; ++i){
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for(int i=1; i<=n; ++i){
		sort(vec[i].begin(),vec[i].end());
	}
	
	dfs(target);
	for(int i = 1; i<=n; ++i){
		visited[i] = 0;
	}
	cout << "\n";
	bfs(target);

}