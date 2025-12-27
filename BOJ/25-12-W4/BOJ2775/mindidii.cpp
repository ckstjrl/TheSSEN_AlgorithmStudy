# include <iostream>
# include <queue>
#include <algorithm>

using namespace std;

int main(){    
    int T;
    cin >> T;
    int a, b;
    
    vector<vector<int>>dp(15, vector<int>(15,0));
    for(int j=1; j<15; j++){
        dp[0][j] = j;
    }
    for(int i=1; i<15; ++i){
        for(int j=1; j<15; ++j){
            if(j==1){
                dp[i][j] = 1;
            }
            
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i=0; i<T; i++){
        cin >> a >> b;
        cout << dp[a][b] <<"\n";   
    }
    return 0;
}