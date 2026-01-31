# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    vector<int>nums(N);
    for(int i=0; i<N; i++)
    {
        cin >> nums[i];
    }

    // M을 초과하지 않는 최댓값
    int max = 0;
    int curr_sum = 0;
    for(int i=0; i<N-2; i++)
    {
        for(int j=i+1; j<N-1; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum > max && curr_sum <= M) max = curr_sum;

            }
        }
    }

    cout << max << '\n';

    return 0;
}