#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main(){
    cin >> T;
    while(T--){

        cin >> N;
        vector<int> coin(N);
        for(int& c : coin){
            cin >> c;
        }

        cin >> M;
        vector<int> dp(M+1, 0);
        dp[0] = 1;

        for(int c : coin){
            for(int j=c; j<=M; ++j){
                dp[j] += dp[j-c];
            }
        }

        cout << dp[M] << "\n";
    }
}