#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;

    vector<int>dp(N+1);

    for(int i=4; i<N+1; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0)
        {
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i%3 == 0)
        {
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }
    cout << dp[N];


    return 0;
}