#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    long long M;
    cin >> N >> M;
    vector<int> tree(N);
    
    for(int i = 0; i<N; ++i){
        cin >> tree[i];
    }

    int low = 0;
    int high = *max_element(tree.begin(),tree.end());
    long long sum = 0;
    int mid, result;

    while(low <= high){
        sum = 0;
        mid = (high + low)/2;
        
        for(int i = 0; i<N; ++i){
            if(tree[i] > mid) sum += tree[i]-mid;
        }

        if(sum >= M){
            result = mid;
            low = mid+1;
        }else if(sum < M){
            high = mid-1;
        }
    }

    cout << result;

}   