// solved(BOJ2798 / B2): 블랙잭
// 부르트포스

#include <bits/stdc++.h>

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	int res = 0;
	for (int i = 0; i < N; ++i) {
		int a = vec[i];
		for (int j = i + 1; j < N; ++j) {
			int b = vec[j];
			for (int k = j + 1; k < N; ++k) {
				int c = vec[k];
				int temp = a + b + c;
				if (temp<= M&& temp >res) {
					res = temp;
				}
			}
		}
	}
	cout << res;
	return 0;
}