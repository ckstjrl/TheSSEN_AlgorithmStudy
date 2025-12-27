#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    string tmp;
    vector<string> nos, nosnoh;

    cin >> N >> M;
    for(int i = 0; i<N; ++i){
        cin >> tmp;
        nos.push_back(tmp);
    }
    
    sort(nos.begin(), nos.end());

    for(int j = 0; j<M; ++j){
        cin >> tmp;
        if(binary_search(nos.begin(), nos.end(), tmp)){
            nosnoh.push_back(tmp);
        }
    }
    sort(nosnoh.begin(), nosnoh.end());
    cout << nosnoh.size() << "\n";

    for(string o : nosnoh){
        cout << o << "\n";
    }
}