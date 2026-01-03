#include <iostream>
#include <deque>

using namespace std;

deque<int> dq; 
int n,m,x;

int main()
{
    deque<int>dp;
    int idx;
    int ans = 0;

    cin >> n >> m;

    for(int i = 1; i <= n ; ++i)
    {
        dq.push_back(i);
    }

    while(m--)
    {
        cin >> x;

        for(int i = 0 ; i < dq.size(); ++i)
        {
            if(dq[i] == x)
            {
                idx = i;
                break;
            }
        }

        if(idx <= dq.size() / 2)
        {
            while(1)
            {
                if(dq.front() == x)
                {
                    dq.pop_front();
                    break;
                }
                ++ans;
                dq.push_back(dq.front());
                dq.pop_front(); 
            }
        }
        else
        {
            while(1)
            {
                if(dq.front() == x)
                {
                    dq.pop_front();
                    break;
                }
                ++ans;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }


    cout << ans<<'\n';


    return 0;
}