# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int num, f1, f2;
vector<int>friends[51];
vector<int>visit;

int bfs(int start)
{
    int max_val = 0;

    queue<pair<int,int>>q;
    q.push({start, 0});

    visit.assign(num+1,-1);
    visit[start] = 0;

    while(!q.empty())
    {
        int curr = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int edge:friends[curr])
        {
            if(visit[edge] == -1) 
            {
                visit[edge] = d + 1;
                q.push({edge,visit[edge]});

                max_val = max(max_val, d+1);
            }
        }
    }
    return max_val;

}


int main()
{
    cin >> num;
    while (1)
    {
        cin >> f1 >> f2;
        if(f1 == -1 && f2 == -1) break;
                friends[f1].push_back(f2);
        friends[f2].push_back(f1);
    }
    

    vector<pair<int,int>>score;
    for(int i=0; i<=num; i++)
    {
        int a = bfs(i);
        score.push_back({a, i});
    }
    sort(score.begin(), score.end());
    
    int min_val = score[1].first;
    
    vector<int>hoobo;
    hoobo.push_back(score[1].second);
    
    int num_hoobo = 1;
    for(int i=2; i<=num; i++)
    {
        if (min_val == score[i].first)
        {
            num_hoobo++;
            hoobo.push_back(score[i].second);
        }
    }

    cout << min_val << " " << num_hoobo << "\n";
    for(int i=0; i<hoobo.size(); i++)
    {
        cout << hoobo[i] << ' ';
    }
    

    return 0;
}