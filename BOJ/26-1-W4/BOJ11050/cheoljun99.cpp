// solved(BOJ11050 / B1): 이항 계수 1
// 조합 공식

#include <bits/stdc++.h>

long long factorial(int n) {
	if (n == 1||n==0) {
		return 1;
	}
	return n * factorial(n - 1);
}

using namespace std;
int main() {
	long long N, K;

	cin >> N >> K;
	long long res = factorial(N) / (factorial(K)*factorial(N-K)) ;
	cout << res;
	return 0;
}