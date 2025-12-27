#if 1
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int r = s.length() % 3;
	if (r == 1) s = "00" + s;
	else if (r == 2) s = "0" + s;

	for (int i = 0; i < s.length(); i += 3)
	{
		int value;

		value = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0') * 1;

		cout << value;
	}


	return 0;
}



#endif