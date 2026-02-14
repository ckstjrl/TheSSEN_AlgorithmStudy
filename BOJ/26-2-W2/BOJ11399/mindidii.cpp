#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> line;

int main()
{
    
    int N;
    cin >> N;
    line.assign(N, 0);

    for(int i=0; i<N; i++)
    {
        cin >> line[i];
    }

    sort(line.begin(), line.end());

    vector<int>prefix(N);
    prefix[0] = line[0];
    for(int i=1; i<N; i++)
    {
        prefix[i] = prefix[i-1] + line[i];
    }

    int sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += prefix[i];
    }

    cout << sum << '\n';

    return 0;
}