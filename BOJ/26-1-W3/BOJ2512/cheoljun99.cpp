// solved(BOJ2512 / S2): 예산
// 이분탐색 사용

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int M;
    vector<int> budget;
    cin >> N;
    for(auto i=0;i<N;i++) {
        int x;
        cin>>x;
        budget.push_back(x);
    }
    cin>> M;
    sort(budget.begin(),budget.end());
    int start=0;
    int end= budget[N-1];
    int result,sum;
    while(start<=end) {
        sum=0;
        int mid = (start+end)/2;
        for(auto i=0; i<N;i++) {
            sum += min(budget[i],mid);
        }
        if(M>=sum) {
            result=mid;
            start=mid+1;
        }else {
            end=mid-1;
        }
    }
    cout << result;
}