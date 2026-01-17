#include <bits/stdc++.h>
using namespace std;

int man, c; // 사람 수, 쿠키 수
int tmp; //임시 저장을 위한 변수
vector<int> v; //쿠키 벡터
int ans; // 정답

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> man >> c;
    
    int h = 0, l = 1, mid = 0;

    for(int i = 0; i<c; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    h = v[c-1];
    
    while(l <= h){
        mid = (l+h)/2;
        int sum = 0;
    
        for(int i = 0; i<c; ++i){
            sum += v[i]/mid;
        }
    
        if(sum >= man){
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    
    cout << ans;
    return 0;
}