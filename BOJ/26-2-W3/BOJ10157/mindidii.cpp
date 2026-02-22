// 자리배정 
#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int C, R, K;
// 시계방향 회전을 위한 방향로직
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool board[1001][1001];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> C >> R >> K;
    if(K > C * R)
    {
        cout << 0;
    }
    else 
    {
        int x = 1, y = 1, num = 1, d = 0;
        while (1)
        {
            if(num == K)
            {
                cout << x << ' ' << y;
                break;
            }
            else 
            {
                board[x][y] = 1;
                int nx = x + dx[d];
                int ny = y + dy[d];
                // 범위 밖을 나가면 
                if(1 > nx || nx < R || 1 > ny || ny < C || board[nx][ny])
                {
                    d = (d+1) % 4;
                    nx = x + dx[d];
                    ny = y + dy[d];
                }
                x = nx;
                y = ny;
                num++;
            }
        }
        
    }


    return 0;
}