# include <iostream>
# include <vector>
using namespace std;

int main(){

    vector<int> square;
    for(int i=0; i<250; i++)
    {
        square.push_back(i*i);
    }

    int N, cnt=0;
    cin >> N;

    for(int a:square)
    {
        if(a == N) 
        {
            cout << 1;
            return 0;
        }
    }

    for(int a : square)
    {
        for(int b : square)
        {
            if(a+b == N) 
            {
                cout << 2;
                return 0;
            }
        }
    }

    for(int a : square)
    {
        for(int b : square)
        {
            for(int c : square) if(a+b+c == N) 
            {
                cout << 3;
                return 0;
            }
        }

    }

    cout << 4;


    return 0;
}


