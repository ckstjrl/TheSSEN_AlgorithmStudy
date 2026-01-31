#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char const &c : s) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(){

    int ans = 0;
    vector<string> a;
    for(int i = 0; i<3; ++i){
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    if(isNumber(a.back())){
        ans = stoi(a.back())+1;
    }else{
        if(a.back() == "FizzBuzz"){
            a.pop_back();
            ans = stoi(a.back())+2;
        }else if(a.back() == "Buzz"){
            a.pop_back();
            if(a.back() == "Fizz"){
                a.pop_back();
                ans = stoi(a.back())+3;
            }else{
                ans = stoi(a.back())+2;
            }
        }else{
            a.pop_back();
            if(a.back() == "Buzz"){
                a.pop_back();
                ans = stoi(a.back())+3;
            }else{
                ans = stoi(a.back())+2;
            }
        }
    }

    if(ans%3 == 0 && ans%5 == 0) cout << "FizzBuzz";
    else if(ans%3 == 0) cout << "Fizz";
    else if(ans%5 == 0) cout << "Buzz";
    else cout << ans;   
}