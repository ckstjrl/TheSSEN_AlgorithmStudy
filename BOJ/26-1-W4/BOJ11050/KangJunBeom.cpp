#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(b == 0){
        cout << 1;
        return 0;
    }else{
        int tmp = 1, div = 1;
        for(int i = a; i>=1; --i){
            tmp *= i;
        }
        for(int j = 1; j <=b; ++j){
            div *= j;
        }
        for(int k = 1; k <= a-b; ++k){
            div *= k;
        }
        cout << tmp/div;
    }
}