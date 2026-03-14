// 동전
#include <iostream>
#include <vector>
using namespace std;

int T, N, price;
vector<int>coins;
int main()
{   
    cin >> T;
    while(T--)
    {
        cin >> N;
        coins.assign(N, 0);

        for(int i=0; i<N; i++)
        {
            cin >> coins[i];
        }
        cin >> price;

        vector<int>dp(price+1, 0);
        dp[0] = 1;

        for(int i=0; i<N; i++)
        {
            for(int j=coins[i]; j<=price; j++)
            {
                dp[j] += dp[j-coins[i]];
            }
        }

        cout << dp[price] << '\n';


    }

    return 0;
}