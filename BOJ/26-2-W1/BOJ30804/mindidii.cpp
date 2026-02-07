// 과일 탕후루

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int>fruits(N);
    for(int i=0; i<N; i++)
    {
        cin >> fruits[i];
    }

    int start = 0, end = 0;
    int diff = 0;
    vector<int>visit(10, 0);
    int len_cnt = 0;
    int max_cnt = -1e9;

    while (end < N)
    {
        if(visit[fruits[end]] == 0)
        {
            diff++;
        }
        visit[fruits[end]]++;
        end++;
        
        while(diff > 2)
        {
            visit[fruits[start]]--;
            if(visit[fruits[start]] == 0)
            {
                diff--;
            }
            start++;
        }
        

        len_cnt = end - start;
        max_cnt = max(len_cnt, max_cnt);


    }
    
    cout << max_cnt << '\n';


    return 0;
}

