// solved(BOJ1780 / S2): 종이의 개수
// 해결방법 : 분할정복
// 메모 : O(N^2logN)

#include<bits/stdc++.h>

using namespace std;

int table[2187][2187];
int paper[3];//0:-1 1:0 2:1

bool check(int x, int y, int N) {
	// 영역에서 같은 숫자로만 이루어져있는지 체크
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++)
			if (table[x][y] != table[i][j])
				return false;
	}
	return true;
}

void recursive(int x, int y, int N) {
	if (check(x, y, N)) {
		paper[table[x][y] + 1] += 1;
		return;
	}
	int n = N / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			recursive(x + i * n, y + j * n, n);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}
	recursive(0, 0, N);
	for (int i = 0; i < 3; i++) cout << paper[i] << "\n";



}