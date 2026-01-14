# include <iostream>
# include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int>line(N+2);
    vector<int>arr(N+2, 0);

    for(int i=0; i<N; i++)
    {
        cin >> line[i];
    }

    for(int i=0; i<N; i++)
    {
        int cnt = 0;
        
        for(int j=0; j<N+1; j++)
        {
            if (arr[j] == 0 && cnt == line[i])
            {
                arr[j] = i+1;
                break;
            }
            else if(arr[j] == 0) cnt++;
        }
    }
    
    for(int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
