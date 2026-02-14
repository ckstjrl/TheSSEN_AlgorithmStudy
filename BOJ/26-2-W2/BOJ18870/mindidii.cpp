#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // 압축을 해야하는 수보다 작은 수의 개수로 압축
    vector<int>coordinate(N);
    for(int i=0; i<N; i++)
    {
        cin >> coordinate[i];
    }

    vector<int>ordered(N);
    copy(coordinate.begin(), coordinate.end(), ordered.begin());
    sort(ordered.begin(), ordered.end());

    ordered.erase(unique(ordered.begin(), ordered.end()),ordered.end());

    
    for(int c:coordinate)
    {
        auto it = lower_bound(ordered.begin(),ordered.end(), c);
        int count = distance(ordered.begin(), it);
        cout << count << " ";
    }
    

    return 0;
}