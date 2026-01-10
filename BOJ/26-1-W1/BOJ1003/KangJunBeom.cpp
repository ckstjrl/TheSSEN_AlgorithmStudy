#include <bits/stdc++.h>
using namespace std;

int zero[41] = {1,};
int one[41] = {0,1,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int j = 2;j<=40; ++j){
        zero[j] = zero[j-1]+zero[j-2];
        one[j] = one[j-1]+one[j-2];
    }
    
    for(int i =0; i<n; ++i){
        int tmp;
        cin >> tmp;
        cout << zero[tmp] << " " << one[tmp] << "\n";
    }

    return 0;
}