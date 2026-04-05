#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int A, B;
		cin >> A >> B;
		string res_str;
		bool visited[10000] = { false };
		queue<pair<int, string>> q;
		q.push({ A,""});
		visited[A] = true;
		while (!q.empty()) {
			int cur_num = q.front().first;
			string cur_str = q.front().second;
			q.pop();
			bool chk = false;
			for (int i = 0; i < 4; ++i) {
				int next_num=0;
				string next_str="";
				if (i == 0) {
					next_num = cur_num * 2 % 10000;
					next_str = cur_str + 'D';
					
				}
				else if (i == 1) {
					next_num = (cur_num == 0) ? 9999 : cur_num - 1;
					next_str = cur_str + 'S';
				}
				else if (i == 2) {
					next_num = (cur_num % 1000) * 10 + (cur_num / 1000);
					next_str = cur_str + 'L';
				}
				else if (i == 3) {
					next_num = (cur_num % 10) * 1000 + (cur_num / 10);
					next_str = cur_str + 'R';
				}
				if (!visited[next_num]) {
					visited[next_num] = true;
					if (next_num == B) {
						res_str = next_str;
						chk = true;
						break;
					}
					q.push({ next_num, next_str });
				}
			}
			if (chk == true)
				break;
		}
		cout << res_str<<'\n';
	}
}