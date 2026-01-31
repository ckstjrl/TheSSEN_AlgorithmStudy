//solved(BOJ15829 / S2): Hashing
// 모듈러 연산은 분배가능

#include <bits/stdc++.h>

using namespace std;

long long power(int base, int exp) {
	long long result = 1;
	while (exp--)
	{
		result = (result * base) % 1234567891;
	}
	return result;
}

int main() {
	int L;
	cin >> L;
	long long temp = 0;
	for (int i = 0; i < L; ++i) {
		char ch;
		cin >> ch;
		int ch_n = ch - 'a' + 1;
		temp += (ch_n * power(31, i));
	}
	cout << temp % 1234567891;
}