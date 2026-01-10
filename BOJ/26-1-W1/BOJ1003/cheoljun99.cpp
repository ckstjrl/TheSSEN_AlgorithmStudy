#include<bits/stdc++.h>

using namespace std;

int zero[41];
int one[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	zero[0] = 1;
	one[0] = 0;
	zero[1] = 0;
	one[1] = 1;
	zero[2] = 1;
	one[2] = 1;

	for (int i = 3; i <= 40; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << zero[N]<<" "<<one[N]<<'\n';
	}
}