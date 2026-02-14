#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    // 수열 A가 주어졌을 때 가장 긴 증가하는 수열 
    int N;
    cin >> N;
    vector<int>nums(N);
    vector<int>dp(N, 1);
    for(int i=0; i<N; i++)
    {
        cin >> nums[i];
    }

    // dp테이블에 현재의 값보다 작은 개수를 count 해서 테이블을 체우기 
    int result = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}