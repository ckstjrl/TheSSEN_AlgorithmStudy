//solved(BOJ2667/ S1): 단지번호붙이기
// bfs 사용

#include<bits/stdc++.h>

using namespace std;

int arr[26][26];
int visited[26][26];
vector<int>res;
queue<pair<int, int>>q; //y,x

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = str[j-1]-'0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				q.push({ i,j });
				visited[i][j] = 1;
				cnt++;
				while (!q.empty()) {
					pair<int,int> next = q.front();
					q.pop();
					
					if (arr[next.first - 1][next.second] == 1 && visited[next.first - 1][next.second] == 0) {
						q.push({ next.first - 1,next.second });
						visited[next.first - 1][next.second] = 1;
						cnt++;
					}
					if (arr[next.first + 1][next.second] == 1 && visited[next.first + 1][next.second] == 0) {
						q.push({ next.first + 1,next.second });
						visited[next.first + 1][next.second] = 1;
						cnt++;
					}
					if (arr[next.first][next.second+1] == 1 && visited[next.first][next.second+1] == 0) {
						q.push({ next.first,next.second+1 });
						visited[next.first][next.second + 1] = 1;
						cnt++;
					}
					if (arr[next.first][next.second - 1] == 1 && visited[next.first][next.second - 1] == 0) {
						q.push({ next.first,next.second - 1 });
						visited[next.first][next.second - 1] = 1;
						cnt++;
					}
					
				}
				res.push_back(cnt);
			}
		}
	}
	sort(res.begin(), res.end(), less<int>());
	cout << res.size()<<'\n';
	for (auto i : res) {
		cout << i << '\n';
	}
}