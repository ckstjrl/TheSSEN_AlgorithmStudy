// solved(BOJ1389/ S1): 케빈 베이컨의 6단계 법칙
// 플루이드 와샬 사용

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N>>M;
	vector<vector<int>> table(101, vector<int>(101, (int)1e9));
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a == b) table[a][b] = 0;
		}
	}
	for (int i = 0; i < M; i++) {  
		int a, b; 
		cin >> a >> b;
		table[a-1][b-1] = 1;
		table[b-1][a-1] = 1;
	}
	for (int k = 0; k < N; k++) {  
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				table[a][b] = min(table[a][b], table[a][k] + table[k][b]);
			}
		}
	}
	vector<int>res(N);   
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			res[a] += table[a][b];
		}
	}
	int min_index = min_element(res.begin(), res.end()) - res.begin(); 
	cout << min_index+1;
	return 0;
}