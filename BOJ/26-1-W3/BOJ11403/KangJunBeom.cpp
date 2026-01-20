#include <bits/stdc++.h>
using namespace std;  

int n;
int tmp;
vector<int> v[101];
int visited[101][101];

void dfs(int start){
	queue<int> q;

	if(v[start].empty()){
		return;
	}

	for(int neighbor : v[start]){
		q.push(neighbor);
	}

	while(q.size()){
		int next = q.front();
		q.pop();
		visited[start][next] = 1;
		for(int i : v[next]){
			if(visited[start][i]) continue;
			q.push(i);
		}

	}

}

int main(){
	cin >> n;

	for(int i = 0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> tmp;
			if(tmp){
				v[i].push_back(j);
			}
		}	
	}

	for(int i = 0; i<n; ++i){
		dfs(i);
	}

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}


}