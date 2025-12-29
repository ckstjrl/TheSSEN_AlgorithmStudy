#include <bits/stdc++.h>
using namespace std;

deque<int> q;
queue<int> ta;
int mv = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, target;
    cin >> n >> target;
    
    for(int i = 1; i<=n; ++i){
        q.push_back(i);
    }
    
    int tmp;

    for(int i = 1; i<=target; ++i){
        cin >> tmp;
        ta.push(tmp);
    }

    while(!ta.empty()){
        auto pos = find(q.begin(), q.end(), ta.front());

        if(pos == q.begin()){
            q.pop_front();
            ta.pop();
        }else if(pos > q.begin()+q.size()/2){
            while(q.front() != ta.front()){
                mv++;
                q.push_front(q.back());
                q.pop_back();
            }
        }else{
            mv++;
            q.push_back(q.front());
            q.pop_front();
        }
    }

    cout << mv;

    return 0;
}