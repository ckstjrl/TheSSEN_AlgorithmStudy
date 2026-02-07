#include <bits/stdc++.h>
using namespace std;

int N;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int arr[26][26];
bool visited[26][26];
int cnt;
vector<int> house;

int bfs(int y, int x){
    cnt = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;

    while(q.size()){
        int tx = q.front().second;
        int ty = q.front().first;
        q.pop();

        for(int i = 0; i<4; ++i){
            int gx = tx + dx[i];
            int gy = ty + dy[i];
            if(gx < 0 || gy < 0 || gx>=N || gy>=N || arr[gy][gx]==0) continue;
            if(visited[gy][gx]) continue;
            q.push({gy,gx});
            visited[gy][gx] = true;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    cin >> N;
    for(int i = 0; i<N; ++i){
        string stmp; int j = 0;
        cin >> stmp;
        for(char c : stmp){
            arr[i][j] = c-'0';
            j++;
        }
    }

    for(int i =0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(arr[i][j] && !visited[i][j]){
                house.push_back(bfs(i,j));
            }
        }
    }
    
    sort(house.begin(),house.end());

    cout << house.size() << "\n";

    for(int num : house){
        cout << num << "\n";
    }

    return 0;

}