//BOJ 2775 부녀회장이 될테야
// DP 사용
#include <bits/stdc++.h>
using namespace std;
int main() {

	int T;
	cin >> T;
	int apt[15][15] = { 0 };

	for (int i = 1; i <= 14; ++i) {
		apt[0][i] = i;
	}
	for (int i = 1; i <= 14; ++i) {
		for (int j = 1; j <= 14; ++j) {
			int temp = 0;
			for (int k = 1; k <= j; ++k) {
				temp += apt[i - 1][k];
			}
			apt[i][j] = temp;
		}
	}
	

	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;
		cout << apt[k][n]<<'\n';
	}

	return 0;
}