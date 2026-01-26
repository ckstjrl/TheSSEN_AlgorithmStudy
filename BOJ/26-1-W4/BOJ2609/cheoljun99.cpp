// solved(BOJ2609 / B1): 최대공약수와 최소공배수
// 유클리드 호제법

#include <bits/stdc++.h>

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int r1;
	int r2;
	if (a < b) {
		r1 = gcd(b, a);
		r2 = lcm(b, a);
	}
	else {
		r1 = gcd(a, b);
		r2 = lcm(a, b);
	}
	cout << r1 << '\n' << r2;
	return 0;
}