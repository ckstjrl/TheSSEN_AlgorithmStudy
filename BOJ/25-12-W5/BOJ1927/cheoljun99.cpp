#include <bits/stdc++.h>
//boj 1927 최소 힙 S2
// stl priority_queue 사용
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> p_q;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (p_q.empty()) cout << 0 << '\n';
			else {
				cout << p_q.top() << '\n';
				p_q.pop();
			}
		}
		else p_q.push(num);
	}
}