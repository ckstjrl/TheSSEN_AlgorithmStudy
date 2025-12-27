# include <iostream>
# include <string>
#include <math.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;

    while(s.length() % 3 != 0){
        s = '0' + s;
    }

    for(int i=0; i<s.length(); i+=3){
        int num = (s[i]-'0') * 4 + (s[i+1]-'0') * 2 + (s[i+2]-'0') *1;
        cout << num;
    }
    cout << "\n";
    return 0;

}