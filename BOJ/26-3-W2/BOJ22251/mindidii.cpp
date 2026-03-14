// 빌런 호석 
# include <iostream>
# include <algorithm>
using namespace std;


int N, K, P, X;
int digit[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

int change()
{
    int res = 0;
    for(int i=1; i<=N; i++)
    {
        if(i == X) continue;

        int cnt = 0;
        int curr = i;
        int target = X;

        for(int j=0; j<K; j++)
        {
            for(int k=0; k<7; k++)
            {
                if(digit[curr % 10][k] != digit[target % 10][k])
                {
                    cnt++;
                }
            }
            curr /= 10;
            target /= 10;
        }

        if(cnt <= P) res++;
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> P >> X;

    cout << change();

    return 0;
}