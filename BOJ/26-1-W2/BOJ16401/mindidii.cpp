# include <iostream>
# include <vector>
# include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    int MAX_len = 0;
    cin >> M >> N;
    vector<int> n_len(N,0);

    for(int i=0; i<N; i++)
    {
        cin >> n_len[i];
        if(MAX_len < n_len[i]) MAX_len = n_len[i];
    }
    
    int snack = 0;
    int left = 1, right = MAX_len;
    
    while(left <= right)
    {
        long long idx = (left + right) / 2;
        if(idx == 0) break;
        long long nephew = 0;

        for(int i=0; i<N; i++)
        { 
            nephew += n_len[i] / idx;

        }
        
        if(nephew < M)
        {
            right = idx - 1;
        }
        if(nephew >= M)
        {
            snack = idx;
            left = idx + 1;
        }


    }

    cout << snack;
    
    return 0;
}

    /*
    whilej
    {  
        int nephew = 0; 
        for(int i=0; i<N; i++)
        {
            if(n_len[i] >= MAX_len)
            {
                int hi = n_len[i] / MAX_len;
                nephew += hi;
            }
        }

        if(nephew < M)
        {
            // cout << "now MAX_len: " << MAX_len << " now nephew: " << nephew << "\n";
            MAX_len--;
            // cout << "change MAX: " << MAX_len << '\n';
        }

        if(nephew >= M)
        {
            // cout << "final MAX_len: " << MAX_len << " final nephew: " << nephew << "\n";
            break;
        }

        if(MAX_len <= 0)
        {
            cout << 0;
            return 0;
        }

    }
    */
