//BOJ 2161 카드 1
//stl 큐 사용
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	queue<int>q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		cout << q.front()<<' ';
		q.pop();

		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
		
	}

}