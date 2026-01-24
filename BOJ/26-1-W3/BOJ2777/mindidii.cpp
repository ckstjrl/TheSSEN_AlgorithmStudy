# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;


int num_play()
{   
    long long N;
    cin >> N;
    int cnt = 0;

    if(N == 1) return 1;

    for(int i=9; i>1; i--)
    {
        while (N % i == 0)
        {
            N /= i;
            cnt++;
        }
    }
    
    if (N != 1) return -1;
    return cnt;
    

}

int main(){
    int T;
    cin >> T;
    
    while(T--)
    {
        cout << num_play() << "\n";
    }

    return 0;
}