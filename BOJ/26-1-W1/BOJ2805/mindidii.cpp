#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int>tree(N+2,0);
    
    for(int i=0; i<N; i++)
    {
        cin >> tree[i];
    }
    
    int max_data = tree[0];
    for(int i = 1; i < tree.size(); i++) 
    {
        if(tree[i] > max_data)
            max_data = tree[i];
    }

    int start =  1;
    int end = max_data;
    long long mid, sum;
    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;

        for(int i=0; i<N; i++)
        {
            if(tree[i] > mid) sum += (tree[i] - mid);
        }

        if (sum < M) end = mid - 1;
        else start = mid + 1;
        

    }
    
    cout << end;

    return 0;
}