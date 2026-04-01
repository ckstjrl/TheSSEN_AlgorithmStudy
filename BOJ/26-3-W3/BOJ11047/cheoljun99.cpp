#include<bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;
	vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), greater<int>());

	int cnt = 0;
	int res = 0;

	while (K != 0) {
		if (K - vec[cnt] >= 0)
		{
			K = K - vec[cnt];
			res++;

		}
		else
			cnt++;
	}
	cout << res;
}