/*
BOJ 2805 나무 자르기 Silver 2
이분 탐색 사용
나무의 개수 최대(N)는 1,000,000 = 백만
나무의 높이 최대(H)는 10,000,000,000 = 10억
나무를 정렬한 상태로 높이의 최소와 높이의 최대를 row와 high로 저장한다.
row와 high의 (row+high)/2 즉 절반 만큼을 자르는 높이(cut)으로 저장한다.
전체 나무 개수 반복 for문을 돌아가면서 각 나무의 위치(namu[i])와 cut을 뺀다. 그 값의 합을 cut_total에 저장
total(집에 가져갈 나무높이)와 cut_total을 비교해서 total<=cut_total 인 경우 row=cut+1 및 해당 cut 값 저장, total > cut_total 인 경우 high=cut-1
해당 과정을 row와 high가 row가 high보다 커지기 전까지 반복한다.
cut중에 high_cut을 구한다.

시간 복잡도 : O(logH * N) = 29,000,000

int -> long long 주의 
low가 0부터 시작이어야함
*/

#include <bits/stdc++.h>

using namespace std;
int main() {
	int N;
	long long M;
	cin >> N >> M;
	vector<long long> namu(N,0);
	for (int i = 0; i < N; ++i) {
		cin >> namu[i];
	}
	sort(namu.begin(), namu.end(), less<long long>());
	long long high = namu[N-1];
	long long low = 0;
	long long answer = 0;
	while (low <= high) {
		long long cut = (low + high) / 2;
		long long cut_total = 0;
		for (int i = 0; i < N; ++i) {
			if (namu[i] > cut) {
				cut_total += (namu[i] - cut);
			}
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