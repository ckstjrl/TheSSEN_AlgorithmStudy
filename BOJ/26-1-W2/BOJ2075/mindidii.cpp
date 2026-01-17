# include <iostream>
#include <queue>
# include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N*N; i++) 
    {
        int temp;
        cin >> temp; 
        pq.push(temp);

        if(pq.size() > N ) 
        {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}