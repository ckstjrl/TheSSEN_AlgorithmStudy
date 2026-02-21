#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<int>nums(N);
    vector<int>dp(N, 1);
    for(int i=0; i<N; i++)
    {
        cin >> nums[i];
    }

    int result = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] > nums[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}