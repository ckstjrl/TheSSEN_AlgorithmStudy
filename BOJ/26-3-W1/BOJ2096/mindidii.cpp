#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int N;
vector<vector<int>>ladder;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int curr_min[3];
    int curr_max[3];
    int nxt[3];

    cin >> curr_min[0] >>  curr_min[1] >> curr_min[2] ;
    curr_max[0] = curr_min[0];
    curr_max[1] = curr_min[1];
    curr_max[2] = curr_min[2];
    
    int a, b, c, d, e, f;
    for(int i=0; i<N-1; i++)
    {
        cin >> nxt[0] >>  nxt[1] >> nxt[2] ;
        a = min(curr_min[0], curr_min[1]) + nxt[0];
        b = min({curr_min[0], curr_min[1], curr_min[2]}) + nxt[1];
        c = min(curr_min[1], curr_min[2]) + nxt[2];

        d = max(curr_max[0], curr_max[1]) + nxt[0];
        e = max({curr_max[0], curr_max[1], curr_max[2]}) + nxt[1];
        f = max(curr_max[1], curr_max[2]) + nxt[2];
        
        curr_min[0] = a;
        curr_min[1] = b;
        curr_min[2] = c;

        curr_max[0] = d;
        curr_max[1] = e;
        curr_max[2] = f;

    }

    cout << max({curr_max[0], curr_max[1], curr_max[2]}) << ' ' << min({curr_min[0], curr_min[1], curr_min[2]}) ;


    return 0;
}