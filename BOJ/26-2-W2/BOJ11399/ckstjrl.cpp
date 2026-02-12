// BOJ 11399. ATM / S4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> time(N);
	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}

	sort(time.begin(), time.end());

    int sum = time[0];
	for (int i = 1; i < N; i++) {
		time[i] = time[i - 1] + time[i];
        sum += time[i];
	}

	cout << sum << "\n";
}

/*
앞 사람의 시간이 누적되어 그 사람의 인출 시간이 늘어난다
이러한 점을 활용하여 최솟값을 구하기 위해 시간이 짧게 걸리는 사람들이 앞에 있어야 한다
정렬 이후 점화식을 활용하여 시간을 구하고 벡터의 모든 요소를 합하여 출력
*/