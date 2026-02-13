// solved(BOJ18870/ S4): 좌표 압축
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int>A(N,0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int>B = A;
	sort(B.begin(),B.end(),less<int>());
	B.erase(unique(B.begin(), B.end()), B.end());
	unordered_map<int, int> un_map;
	for (int i = 0; i < B.size(); ++i) {
		un_map[B[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		cout << un_map[A[i]] << ' ';
	}
}