// 부분 수열의 합 
# include <iostream>
# include <vector>
using namespace std;

int N, S;
int sum, cnt;
vector<int>nums(N+1);


void recur(int idx, int sum){
    if(idx == N){
        if(S == sum){
            cnt++;
        }
        return;
    }

    recur(idx+1, sum + nums[idx]);
    recur(idx+1, sum);

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    nums.resize(N+2);
    
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }

    if(S == 0) cnt--;

    recur(0,0);
    cout << cnt;

    return 0;
}