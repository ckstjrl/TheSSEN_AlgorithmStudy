#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int ans[n] = {0};
    int input[n] = {0};

    for(int i= 0 ;i<n; ++i){
        cin >> input[i];
    }

    for(int i=0; i<n; ++i){
        int count = 0;
        for(int j = 0; j<n; ++j){
            if(ans[j]==0)
            {
                if(count == input[i]){
                    ans[j] = i+1;
                    break;
                }
                count++;
            }
        }
    }
    
    for(int i = 0; i<n; ++i){
        cout << ans[i] << " ";
    }
    
}