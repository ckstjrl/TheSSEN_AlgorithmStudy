    /*
        파스칼의 삼각형
        누적합
        체감 난이도 : 쉬움
    */

    #include <bits/stdc++.h>
    using namespace std;

    long long arr[31][31];
    
    // arr[i][j] = arr[i-1][j-1] + arr[i-1][j];

    int main(){
        int n,k;
        cin >> n >> k;
        arr[1][1] = 1;

        for(int i = 2; i<=n; ++i){
            for(int j = 1; j <=k; ++j){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }

        cout << arr[n][k];
        
    }