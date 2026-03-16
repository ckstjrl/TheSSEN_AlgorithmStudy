# include <iostream>
# include <vector>
using namespace std;

int N, M;
vector<int>A;


int main()
{
    cin >> N >> M;
    A.resize(N);

    long long a;
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int start = 0;
    int end = 1;
    long long min_diff = 2e9;
    while (end < N)
    {
        long long diff = A[end] - A[start];

        if(diff < M)
        {
            end++;
        }

        else
        {
            min_diff = min(min_diff, diff);
            start++;

            if(start > end) end++;
        }

    }
    cout << min_diff;
    
    return 0;
}