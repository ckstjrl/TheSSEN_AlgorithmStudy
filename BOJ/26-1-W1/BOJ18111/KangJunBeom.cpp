#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int height = 0;
    int time = 99999999;
    int min = 257, max = 0;
    int n, m, b;
    cin >> n >> m >> b;
    int world[n][m] = {0};
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> world[i][j];
            if(world[i][j] > max) max = world[i][j];
            if(world[i][j] < min) min = world[i][j];
        }
    }

    for(int h = min; h<=max; ++h){
        int tmp_time = 0;
        int need_b = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(h > world[i][j]){
                  need_b += (h-world[i][j]);
                  tmp_time += (h-world[i][j]);  
                }else{
                    need_b -= (world[i][j]-h);
                    tmp_time += (world[i][j]-h)*2;
                }
            }
        }
        if(need_b > b) continue;
        else{
            if(tmp_time <= time){
                time = tmp_time;
                height = h;
            }
        }
    }

    cout << time << " " << height;
}   