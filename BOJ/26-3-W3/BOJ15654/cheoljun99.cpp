#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr_main[8];// 주 수열
int arr_sub[8]; // 보조 수열
bool used[8];

void backtracking(int k) {

	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr_main[arr_sub[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i <N; i++) {
		if (!used[i]) {
			arr_sub[k] = i;
			used[i] = 1;
			backtracking(k + 1);
			used[i] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr_main[i];
	sort(arr_main, arr_main + N);

	backtracking(0);
}