#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    string ans = "";
    int tmp_n;
    cin >> tmp;
    if(tmp.size()%3==1){
        tmp = "00" + tmp;
    }
    if(tmp.size()%3==2){
        tmp = "0" + tmp;
    }

    for(int i = 0; i<=tmp.size()-3; i+=3){
        tmp_n = (tmp[i]-'0')*4+(tmp[i+1]-'0')*2+(tmp[i+2]-'0');
        ans += (tmp_n + '0');
    }

    cout << ans;

    return 0;
}