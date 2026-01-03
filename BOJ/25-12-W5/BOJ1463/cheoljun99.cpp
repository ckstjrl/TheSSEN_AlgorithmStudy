#include<bits/stdc++.h>
//boj 1463 1로만들기 S3
//dp 사용
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int>dpVector(N+1, 0);
	dpVector[1] = 0;
	for (int i = 2; i <= N; i++) {
		dpVector[i] = dpVector[i-1] + 1;
		if (i % 2 == 0)
			dpVector[i] = min(dpVector[i], dpVector[i / 2] + 1);
		if (i % 3 == 0)
			dpVector[i] = min(dpVector[i], dpVector[i / 3] + 1);
	}
	cout << dpVector[N] << '\n';
}