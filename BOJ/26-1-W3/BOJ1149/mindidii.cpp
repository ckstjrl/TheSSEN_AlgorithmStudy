# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;  


int main(){

    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(3));
    for(int i=0; i<N; i++)
    {
        cin >> graph[i][0] >>  graph[i][1] >>  graph[i][2];
    }

    vector<vector<int>>dp(N, vector<int>(3));
    dp[0][0] = graph[0][0];
    dp[0][1] = graph[0][1];    
    dp[0][2] = graph[0][2];

    for(int i=1; i<N; i++)
    {
        dp[i][0] = graph[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = graph[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = graph[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2] }) << '\n';

    return 0;
}



