# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int main(){
    int N, max_budget, max_value = 0, min_value;
    cin >> N;
    vector<int>budgets(N+2);
    for(int i=0; i<N; i++)
    {
        cin >> budgets[i];
        if(budgets[i] > max_value) max_value = budgets[i];
    }
    cin >> max_budget;

    int left = 1;
    int right = max_value;
    int max_curr = 0;

    while(left <= right)
    {
        int curr = (left+right)/2;
        int curr_sum = 0;
        for(int i=0; i<N; i++)
        {
            if(budgets[i] > curr)
            {
                curr_sum += curr;
            }
            else{
                curr_sum += budgets[i];
            }
        }

        if(curr_sum > max_budget) 
        {
            right = curr - 1;
        }
        else 
        {
            left = curr + 1;
            max_curr = max(max_curr, curr);
        }


    }

    cout << max_curr;


    return 0;
}