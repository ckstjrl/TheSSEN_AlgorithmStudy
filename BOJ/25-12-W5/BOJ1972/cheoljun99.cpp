//BOJ 1972 놀라운 문자열
//해시 맵 사용
//시간 복잡도는 고려하지 않아도 될 것같음
//N 거리의 문자열을 잘라 내는 방식을 2중 for문 사용
// 바깥 for문은 가능한 N거리 카운트
// 안쪽 for문은 N거리 만큼 떨어진 두 글자가 string 범위 안쪽인지 확인함
#include <bits/stdc++.h>
using namespace std;
int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "*") break;
		int N = str.size() - 2;
		if (N < 0) N = 0;
		bool chk = false;
		for (int i = 0; i <= N; ++i) {
			unordered_map<string, int> un_map;
			for (int j = 0; j < str.size(); ++j) {
				if (j + i + 1 >= str.size()) break;
				string temp = "";
				temp.push_back(str[j]);
				temp.push_back(str[j + i + 1]);
				if (un_map.find(temp) != un_map.end()) {
					chk = true;
					cout << str << " " << "is NOT surprising." << endl;
					break;
				}
				else un_map.insert({ temp,1 });
			}
			if (chk == true) break;
		}
		if (chk == false) cout << str << " " << "is surprising." << endl;
	}
	return 0;
}