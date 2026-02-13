    #include <iostream>
    #include <string>
    #include <vector>
    #include <queue>

    using namespace std;

    int n, m;
    vector<vector<int>>friends;
    int visit[501];

    void bfs(int start)
    {
        queue<int>q;
        q.push(start);
        visit[1] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int i=0; i<friends[curr].size(); i++)
            {
                int nxt = friends[curr][i];
                if(visit[nxt] == -1)
                {
                    visit[nxt] = visit[curr] + 1; 
                    q.push(nxt);
                }
            }
        }
        


    }

    int main()
    {
        cin >> n >> m;
        friends.assign(n + 1, vector<int>());
        fill(visit, visit+501, -1);
        int check = false;
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin >> a >> b;
            friends[a].push_back(b);
            friends[b].push_back(a);
            if( a == 1 || b == 1) check = true;
        }
        
        int cnt = 0;
        if(!check)
        { 
            cout << 0 << '\n';
            
        }
        else {
            bfs(1); 
            for(int i=0; i<n+2; i++)
            {
                if(visit[i] == 1 || visit[i] == 2) cnt++;
            }
            cout << cnt << '\n';
        }

        return 0;

    }