// solved(BOJ11399/ S4): ATM 
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];

	sort(vec.begin(), vec.end());

	int ans = 0;
	int save = 0;
	for (int i = 0; i < N; i++) { 
		ans = ans + vec[i];
		save += ans; 
	}

	cout << save;

}