#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<ll> card;
    for(int i = 0; i<n; ++i){
        ll tmp;
        cin >> tmp;
        card.push(-tmp);
    }

    for(int i = 0; i<m; ++i){
        ll sum_tmp  = 0;
        sum_tmp += card.top();
        card.pop();
        sum_tmp += card.top();
        card.pop();
        for(int j=0; j<2; ++j){
            card.push(sum_tmp);
        }
    }

    ll sum = 0;

    while(!card.empty()){
        sum -= card.top();
        card.pop();
    }

    cout << sum;

}