#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N, K;
vector<pair<int, int>>obj;

int main()
{

    cin >> N >> K;

    int w, v;
    for(int i=0; i<N; i++)
    {
        cin >> w >> v;
        obj.push_back({w, v});
    }

    vector<int>dp(K+1, 0);
    for(int i=0; i<N; i++)
    {
        int weight = obj[i].first;
        int value = obj[i].second;

        for(int j=K; j>=weight; j--)
        {
            dp[j] = max(dp[j], dp[j-weight] + value);
        }

        
    }

    cout << dp[K];


    return 0;
}