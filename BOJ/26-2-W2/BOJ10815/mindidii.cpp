#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int nums[20000002]; // 지역변수로 사용하면 stack 영역에 저장하기 때문에 값이 터짐

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    int a;
    for(int i=0; i<N; i++)
    {
        cin >> a;
        nums[a + 10000000] = 1;
    }

    int M;
    cin >> M;
    int b;
    for(int i=0; i<M; i++)
    {
        cin >> b;
        if(nums[b + 10000000] == 1) cout << 1 <<' ';
        else cout << 0 << ' ';
    }

    return 0;
}