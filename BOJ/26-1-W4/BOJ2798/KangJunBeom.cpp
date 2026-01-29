#include <iostream>
using namespace std;

int main() {
	int a, b;
	int tmp = 0;
	int ans = 0;

	cin >> a >> b;

	int c[100];

	for (int i = 0; i < a; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i < a - 2; ++i) {
		for (int j = i+1; j < a - 1; ++j) {
			for (int k = j + 1; k < a; ++k) {
				tmp = c[i] + c[j] + c[k];
				if (tmp <= b && ans < tmp) ans = tmp;
			}
		}
	}

	cout << ans;
}
