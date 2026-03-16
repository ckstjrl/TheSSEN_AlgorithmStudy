#include <bits/stdc++.h>
using namespace std;

// 상단 비트 0번 / 좌상 비트 1번 / 우상 비트 2번 / 중간 비트 3번 
// 죄하 비트 4번 / 우하 비트 5번 / 하단 비트 6번
// 0 : 1110111 / 1 : 0010010 / 2 : 1011101 / 3 : 1011011 / 4 : 0111010
// 5 : 1101011 / 6 : 1101111 / 7 : 1010010 / 8 : 1111111 / 9 : 1111011
string arr_ch[10] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011",
};

int N, K, P, X;

int main(){
    cin >> N >> K >> P >> X;
    int cost[10][10];
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            int diff = 0;
            for(int k = 0; k<7; ++k){
                if(arr_ch[i][k] != arr_ch[j][k]) diff++;
            }
            cost[i][j] = diff;
        }
    }

    int ans = 0;

    for (int target = 1; target <= N; target++) {

        int tempX = X; 
        int tempTarget = target;
        int total_diff = 0;

        for (int i = 0; i < K; i++) {
            int digitX = tempX%10; 
            int digitTarget = tempTarget%10;

            total_diff += cost[digitX][digitTarget];

            tempX = tempX/10;
            tempTarget = tempTarget/10;
        }

        if (total_diff >= 1 && total_diff <= P) {
            ans++;
        }
    }

    cout << ans;

}