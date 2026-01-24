// solved(BOJ2777 / S2): 숫자 놀이
// 그리디 사용

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int cnt = 0;
        if (N == 1)
        {
            cnt = 1;
        }
        else
        {
            for (int i = 9; i >= 2; --i)
            {
                while (N % i == 0)
                {
                    N /= i;
                    ++cnt;
                }
            }
            if (N > 1)
            {
                cnt = -1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}