#if 1
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int N, M;
set<string>name;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map<string, int> peopleInfo;

	for (int i = 0; i < N + M; ++i)
	{
		string s;
		cin >> s;

		peopleInfo[s]++;

		if (peopleInfo[s] == 2)
		{
			name.insert(s);
		}
	}

	cout << name.size() << '\n';

	for (string x : name)
	{
		cout << x << '\n';
	}

	return 0;
}

#endif