#if 01
#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	queue<int>q;

	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	int y;

	if (N == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	while (q.size() > 1)
	{
		y = q.front();
		cout << y << ' ';
		q.pop();

		y = q.front();
		q.pop();
		q.push(y);
	}

	cout << y << '\n';

	return 0;
}
#endif