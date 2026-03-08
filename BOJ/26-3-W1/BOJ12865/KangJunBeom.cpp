    /*
        평범한 배낭
        DP/배낭
        체감 난이도 : 보통
    */

    #include <bits/stdc++.h>
    using namespace std;

    int dp[101][100001];
    int W[101], V[101];

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N, M;
        cin >> N >> M;
        for(int i = 1; i<=N; ++i){
            cin >> W[i] >> V[i];
        }

        for(int i = 1; i<=N; ++i){
            for(int j = 1; j<=M; ++j){
                if(W[i] <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout << dp[N][M];

    }