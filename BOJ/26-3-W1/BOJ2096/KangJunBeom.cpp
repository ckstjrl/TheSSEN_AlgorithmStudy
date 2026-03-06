    /*
        내려가기
        DP
        체감 난이도 : 보통
    */

    #include <bits/stdc++.h>
    using namespace std;

    int max_dp[3];
    int min_dp[3];
    int arr[100001][3];
    int n;

    int main(){ 
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;

        for(int i = 1; i<=n; ++i){
            for(int j = 0; j<3; ++j){
                cin >> arr[i][j];
            }
        }

        for(int i = 1; i<=n; ++i){
            int prev0, prev1, prev2;
            prev0 = max_dp[0];
            prev1 = max_dp[1];
            prev2 = max_dp[2];
            max_dp[0] = max(prev0,prev1) + arr[i][0];
            max_dp[1] = max({prev0,prev1,prev2}) + arr[i][1];
            max_dp[2] = max(prev1,prev2) + arr[i][2];
        }

        for(int i = 1; i<=n; ++i){
            int prev0, prev1, prev2;
            prev0 = min_dp[0];
            prev1 = min_dp[1];
            prev2 = min_dp[2];
            min_dp[0] = min(prev0,prev1) + arr[i][0];
            min_dp[1] = min({prev0,prev1,prev2}) + arr[i][1];
            min_dp[2] = min(prev1,prev2) + arr[i][2];
        }        

        int max_score = max( {max_dp[0], max_dp[1], max_dp[2]} );
        int min_score = min( {min_dp[0], min_dp[1], min_dp[2]} );
        cout << max_score << " " <<min_score;

    }
