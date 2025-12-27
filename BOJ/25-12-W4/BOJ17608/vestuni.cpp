#if 01
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	stack<int>Stick;

	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		Stick.push(x);
	}

	int Max = 0;
	int answer = 0;

	for (int i = 0; i < N; ++i)
	{
		if (Max < Stick.top())
		{
			Max = Stick.top();
			++answer;
		}

		Stick.pop();
	}

	cout << answer << '\n';

	return 0;
}
#endif