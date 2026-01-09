#include <iostream>
#include <vector>
using namespace std;



int main(){
    int T, N;
    cin >> T;
    vector<pair<int,int>>fibo;
    fibo.push_back({1,0});
    fibo.push_back({0,1});

    for(int i=2; i<=40; i++)
    {
        pair<int,int> a = fibo[i-2];
        pair<int,int> b = fibo[i-1];
        fibo.push_back({a.first+b.first, a.second + b.second});
    }


    for(int i=0; i<T; i++)
    {
        cin >> N;
        cout << fibo[N].first << " " << fibo[N].second << '\n';
    }



    return 0;
}

