// 카드합체 놀이
# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>>card;

int main()
{
    cin >> n >> m;
    int a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        card.push(a);
    }
    
    while(m--)
    {
        long long m1 = card.top();
        card.pop();
        long long m2 = card.top();
        card.pop();

        long long push_val = m1 + m2;
        card.push(push_val);
        card.push(push_val);
    }

    long long min_val = 0;
    for(int i=0; i<n; i++)
    {
        min_val += card.top();
        card.pop();
    }

    cout << min_val;

    return 0;
}