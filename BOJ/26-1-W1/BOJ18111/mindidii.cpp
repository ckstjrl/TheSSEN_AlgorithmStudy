#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, B;
    int min_h = 256, max_h = 0;
    if (!(cin >> N >> M >> B)) return 0;
    vector<vector<int>> land(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
            if (land[i][j] < min_h) min_h = land[i][j];
            if (land[i][j] > max_h) max_h = land[i][j];
        }
    }

    int ans_time = INT_MAX;
    int ans_height = -1;

    for(int h = min_h; h <= max_h; h++)
    {
        int remove = 0;
        int build = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if(land[i][j] > h) remove += (land[i][j] - h);
                else if(land[i][j] < h) build += (h - land[i][j]);
            }
        }
        
        if(B + remove >= build) 
        {
            int time = build + remove*2;
            if(time <= ans_time) 
            {
                ans_time = time;
                ans_height = h;
            }
        }

    }
    cout << ans_time << " " << ans_height;
   
}