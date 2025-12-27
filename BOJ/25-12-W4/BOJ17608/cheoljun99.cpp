// BOJ 17608 막대기
// stl stack 사용
/*  바라보는 첫번째 건물을 오른쪽 피연산자로 두고 두번째 건물부터 왼쪽 피연산자로 두고
    비교 연산을 수행한다. 비교 연산에서 왼쪽 피연산자가 오른쪽 피연산자 보다 큰 경우
    오른쪽 피연산자 값을 왼쪽 피연산자 값으로 변경한다. 이과정에서 오른쪽 피연산자가 된 값의 개수를 저장하면
    답을 구할 수 있다. 스택 자료구조를 사용하여 수행할 수 있다.
*/ 
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>vec(N, 0);

	for (int i = N - 1; i > -1; i--) {
		cin >> vec[i];
	}

	stack<int>st;
	for (int i = 0; i < N; i++) {
		if (st.empty()) {
			st.push(vec[i]);
		}
		else {
			if (st.top() < vec[i]) {
				st.push(vec[i]);
			}
		}
	}
	cout << st.size();

}