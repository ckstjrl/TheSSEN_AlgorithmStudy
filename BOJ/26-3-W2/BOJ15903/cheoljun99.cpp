/*
solved(BOJ15903 / S2): 카드 합체 놀이

x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.
점수를 낮게 만드는것만 고른다.
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<long long,vector<long long>,greater<long long>>pQ;

	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		pQ.push(a);
	}

	for (int i = 0; i < m; i++) {
		long long x = pQ.top();
		pQ.pop();
		long long y = pQ.top();
		pQ.pop();
		long long temp = x + y;
		pQ.push(temp);
		pQ.push(temp);
	}
	long long res = 0;
	while (!pQ.empty()) {
		res += pQ.top();
		pQ.pop();
	}
	cout << res;
}