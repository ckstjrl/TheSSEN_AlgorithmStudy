#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;

int map[100][100];
bool Visited[100][100];
int Dist[100][100];

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0, 0 , -1 ,1 };

bool CheckIn(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	Visited[y][x] = true;
	Dist[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << Dist[y][x] << '\n';
			return 0;
		}

		for (int index = 0; index < 4; index++)
		{
			int ny = y + dy[index];
			int nx = x + dx[index];

			if (!CheckIn(ny, nx) || Visited[ny][nx] || map[ny][nx] == 0) continue;

			Visited[ny][nx] = true;
			Dist[ny][nx] = Dist[y][x] + 1;
			q.push({ ny,nx });
		}

	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	memset(Visited, false, sizeof(Visited));
	memset(Dist, 0, sizeof(Dist));


	for (int i = 0; i < N;i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);

	return 0;
}