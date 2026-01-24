// solved(BOJ11403/ S1): 경로 찾기
// 플루이드 와샬 사용

#include <bits/stdc++.h>

using namespace std; 
int table[105][105]; 
int main() {
	int N; 
    cin >> N; 
	for(int i=0; i<N; i++){
		for (int j = 0; j < N; j++) {
			cin >> table[i][j]; 
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (table[i][k] && table[k][j]) {
					table[i][j] = 1; 
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << table[i][j] << " ";
		}cout << endl; 
	}
}
