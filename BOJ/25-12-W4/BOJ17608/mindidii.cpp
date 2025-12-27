# include <iostream>
# include <vector>
#include <algorithm>

using namespace std;

void solution(int N){
    vector<int> H;
    int h;
    for (int i=0; i<N; i++){
        cin >> h;
        H.push_back(h);
    }

    int current_max = H.back(); 
    int count = 1;

    for(int i = H.size() - 2; i >= 0; --i){
        if(H[i] > current_max) { 
            count++;
            current_max = H[i];
        }
    }

    cout << count << "\n";
}

int main(){

    int N;
    cin >> N;
    solution(N);
    
    return 0;
}