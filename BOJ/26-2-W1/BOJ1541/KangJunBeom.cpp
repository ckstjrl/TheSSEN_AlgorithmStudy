#include <bits/stdc++.h>
using namespace std;

string input, num;
int sum, tmp;
bool flag;

int main(){
    cin >> input;

    for(auto a : input){
        if(a >='0' && a<='9') num += a;
        else{
            tmp = atoi(num.c_str());
            num = "";
            if(flag) sum -= tmp;
            else sum += tmp;
            if(a == '-') flag = true;
        }
    }

    tmp = atoi(num.c_str());
    if(flag) sum -= tmp;
    else sum += tmp;

    cout << sum;
}