#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    
    vector<int> num(N);
    vector<int> dp(N,1);

    for(int i = 0; i<N; ++i){
        cin >> num[i];
    }

    for(int i = 1; i<N; ++i){
        for(int j = 0; j<i; ++j){
            if(num[i]>num[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    
    cout << *max_element(dp.begin(),dp.end());
}