// solved(BOJ16401 / S2): 과자나눠 주기
// 해결방법 : 이진 탐색으로 해결
// 메모 : O(NlogN+NlogL) L은 과자 max 길이 
#include <bits/stdc++.h>

using namespace std;
int main() {
	int M;
	long long N;
	cin >> M >> N;
	vector<long long> makdae(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> makdae[i];
	}
	sort(makdae.begin(), makdae.end(), less<long long>());
	long long high = makdae[N - 1];
	long long low = 1;
	long long answer = 0;
	while (low <= high) {
		long long cut = (low + high) / 2;
		long long cut_total = 0;
		for (int i = 0; i < N; ++i) {
			cut_total += makdae[i] / cut;
			if (cut_total >= M) break;
		}
		if (cut_total >= M) {
			answer = cut;
			low = cut + 1;
		}
		else {
			high = cut - 1;
		}
	}
	cout << answer;
	return 0;
}