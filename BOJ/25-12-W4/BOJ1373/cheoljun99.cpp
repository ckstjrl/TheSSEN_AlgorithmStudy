//BOJ 1373 2진수 8진수
//STL string 사용
//STL reverse 시간복잡도가 요소가 N일때 O(N)
#include <bits/stdc++.h>

using namespace std;
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	string res="";
	int temp = 0;
	for (int i = str.size()-1; i>=0; --i) {
		if (str[i] == '1') {
			temp += pow(2, cnt);
			cnt++;
		}
		else {
			cnt++;
		}
		if (cnt == 3) {
			res.push_back('0'+temp);
			cnt = 0;
			temp = 0;
		}
	}
	if (temp != 0) {
		res.push_back('0' + temp);
	}
	if(res.empty())
		res.push_back('0');
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}