// solved(BOJ1182 / S2): 부분수열의 합
// 해결방법 : 백트레킹
// 메모 : O(2^N) 가지치기로 효율성 증가

#include<bits/stdc++.h>

using namespace std;

int N, S;
int arr[20];
int cnt;


void backtracking(int depth,int cur,int sum) {
	if (depth !=0&&sum == S) {
		cnt++;
	}
	if (depth == N) {
		return;
	}
	for (int i = cur; i < N; i++) {
		
		backtracking(depth + 1, i+1,sum + arr[i]);
		
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N>>S;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	backtracking(0,0,0);
	cout << cnt;
}