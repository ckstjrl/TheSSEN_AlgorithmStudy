# include <iostream>
# include <queue>
#include <algorithm>

using namespace std;

int N;
queue<int> q;

void solution(int N){
    
    for(int i=1; i<N+1; i++){
        q.push(i);
    }
    while(q.size() != 1){
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}

int main(void){

    cin >> N;
    solution(N);
    

    return 0;
}