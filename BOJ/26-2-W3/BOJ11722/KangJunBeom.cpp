#include <bits/stdc++.h>
using namespace std;

int main(){
    int len;
    cin >> len;
    vector<int> arr(len,0);
    vector<int> dp(len, 1);
    for(int i = 0; i<len; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i<len; ++i){
        for(int j = 0; j<i; ++j){
            if(arr[i]<arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

}