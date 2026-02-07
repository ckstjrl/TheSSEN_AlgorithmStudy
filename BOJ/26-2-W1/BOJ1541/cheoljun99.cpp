// solved(BOJ1541/ S2): 잃어버린 괄호
// - 만나면 괄호 시작인데 또 - 만나면 걍 그앞에서 괄호 닫고 다시 괄호 열었다고 생각



#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	cin >> input;
	bool chk=0;
	string num;
	int res = 0;
	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || i == input.size() ) {
			if (chk == 1) {
				res -= stoi(num);
				num = "";
			}
			else {
				res += stoi(num);
				num = "";
			}
		}
		else {
			num += input[i];
		}
		if (input[i] == '-') {
			chk = 1;
		}
	}
	cout << res;
}