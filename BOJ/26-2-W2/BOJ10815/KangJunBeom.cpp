#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tmp, a, num;
    cin >> tmp;
    for(int i = 0; i<tmp; ++i){
        cin >> a;
        m[a]++;
    }
    cin >> num;
    for(int i =0; i<num; ++i){
        cin >> a;
        if(m[a] == 0) cout << 0 << " ";
        else cout << 1 << " ";
    }
}