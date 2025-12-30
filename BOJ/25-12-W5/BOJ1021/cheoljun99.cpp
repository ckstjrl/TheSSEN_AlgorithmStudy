/*
BOJ 1021 회전하는 큐 siver 3
stl deque 사용
시간 복잡도는 고려하지 않아도 될 것같음
걍 부르트포스해버림
뽑아내야할 값을 del_num으로 두고
뒤에서 뽑아서 앞으로 보내는 연산으로 del_num이 나올 deque와
앞에서 뽑아서 뒤로 보내는 연산으로 del_num이 나올 deque를 모두 구해서
가장 적은 횟수의 연산을 사용한 deque를 원본 main_deque로 덮어쓰기함 
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	std::deque<int> main_deque;
	for (int i = 1; i <= N; ++i) {
		main_deque.push_back(i);
	}
	std::deque<int>del_list;
	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		del_list.push_back(num);
	}
	int total = 0;
	while (!del_list.empty()) {
		int del_num = del_list.front();
		std::deque<int> front_method = main_deque;
		std::deque<int> back_method = main_deque;
		int cnt = 0;
		while (front_method.front() != del_num && back_method.front() != del_num) {
			++cnt;
			int front_temp = front_method.front();
			front_method.pop_front();
			front_method.push_back(front_temp);
			int back_temp = back_method.back();
			back_method.pop_back();
			back_method.push_front(back_temp);
		}
		if (front_method.front() == del_num) {
			front_method.pop_front();
			main_deque = front_method;
		}
		else if(back_method.front() == del_num){
			back_method.pop_front();
			main_deque = back_method;
		}
		del_list.pop_front();
		total += cnt;
	}
	cout << total << endl;
	return 0;
}