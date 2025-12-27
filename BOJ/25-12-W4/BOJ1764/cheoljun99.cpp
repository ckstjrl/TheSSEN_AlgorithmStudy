//BOJ1764 듣보잡
//해시 테이블 사용
//시간 복잡도 O(N)
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> un_map;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		un_map.insert({ str,1 });
	}
	for (int i = 0; i < M; ++i) {
		string str;
		cin >> str;
		if (un_map.find(str) != un_map.end()) {
			un_map[str]++;
		}
	}
	vector<string> res;
	for (unordered_map<string, int>::iterator iter = un_map.begin(); iter != un_map.end(); ++iter) {
		if (iter->second > 1) res.push_back(iter->first);
	}
	sort(res.begin(), res.end(), less<string>());
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << '\n';
	}
	return 0;
}