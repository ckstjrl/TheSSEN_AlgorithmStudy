// solved(BOJ10815/ S5): 숫자 카드

#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	map<int,int>m;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		m.insert({ num, 0 });
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (m.find(num) == m.end()) cout<<0<<' ';
		else cout<<1<<' ';
	}
	
	
}