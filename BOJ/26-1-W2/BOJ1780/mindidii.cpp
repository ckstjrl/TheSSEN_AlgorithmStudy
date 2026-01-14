// 종이의 개수 
# include <iostream>
# include <vector>
using namespace std;

vector<vector<int>> map;
vector<int> num(3,0);

bool check(int row, int col, int num){
    
    int n = map[row][col];

    for(int i = row; i<row+num; i++)
    {
        for(int j=col; j<col+num; j++)
        {
            if(n != map[i][j]) return false;
        }
    }
    return true;
}

void recur(int row, int col, int n){

    int now = map[row][col];
    
    if(!check(row, col, n))
    {
        int size = n/3;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                recur(row+i*size,col+j*size, size);
            }
        }
    }
    else
    {
        num[now+1]++; 
        return;
    }


}


int main(){
    int N;
    cin >> N;
    map.assign(N, vector<int>(N));
    num.resize(3,0);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }

    recur(0,0,N);
    cout << num[0] << "\n" << num[1] << "\n" << num[2];

    return 0;
}
