#include<bits/stdc++.h>

using namespace std;

void calculation(int N) {

	int midleSize = pow(3, N - 1);

	if (N == 0) {
		cout << "-";
		return;
	}
	calculation(N - 1);
	for (int i = 0; i < midleSize; i++) {
		cout << " ";
	}
	calculation(N - 1);



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	while (cin >> N) {
		calculation(N);
		cout << "\n";
	}

}