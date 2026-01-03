# include <iostream>
# include <string>
# include <vector>
#include <set>

using namespace std;
string N;


int main(){
        
    vector<string> pair;
    while(1)
    {
        cin >> N;
        bool check = true;
        int n_size = N.size();
        if(N == "*")
        {
            break;
        }
        for(int d=1; d<n_size-1 && check; d++)
        {
            set<string> seen;
            for(int i=0; i+d < n_size; i++)
            {
                string pair = "";
                pair += N[i];
                pair += N[i+d];
                if (seen.find(pair) != seen.end())
                {
                    check = false;
                    break;
                }
                seen.insert(pair);
            }
        }

        if(!check) 
        {
            cout << N << " is NOT surprising."<< endl;
        }
        else
        {
            cout << N << " is surprising."<< endl;
        }

    }

    return 0;
}
