#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int front;
    int tmp;
    int cnt = 1;
    vector<int> stick;
    int n;

    cin >> n;

    for(int i =0; i<n; ++i){
        cin >> tmp;
        stick.push_back(tmp);
    }

    front = stick.back();
    stick.pop_back();

    while(!stick.empty()){
        if(front<stick.back()){
            cnt++;
            front = stick.back();
        }
        stick.pop_back();
    }

    cout << cnt;

    return 0;
}