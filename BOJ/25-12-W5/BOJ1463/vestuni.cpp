#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<bool>visited;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	visited.resize(N + 1, false);
	queue<pair<int, int>>q; // {숫자, count}
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int num = q.front().first;
		int Count = q.front().second;
		q.pop();

		if (num == N) // 종료 조건
		{
			cout << Count << '\n';
			break;
		}

		int first = num * 3;
		int second = num * 2;
		int third = num + 1;

		if (first <= N && !visited[first])
		{
			visited[first] = true;
			q.push({ first, Count + 1 });
		}

		if (second <= N && !visited[second])
		{

			visited[second] = true;
			q.push({ second, Count + 1 });
		}

		if(third <= N && !visited[third])
		{

			visited[third] = true;
			q.push({ third, Count + 1 });
		}
	}

	return 0;
}