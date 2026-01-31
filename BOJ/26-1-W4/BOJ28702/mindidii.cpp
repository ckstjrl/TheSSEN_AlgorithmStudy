#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string s;
    int target, result;
    for(int i=0; i<3; i++)
    {
        cin >> s;
        if(isdigit(s[0]))
        {
            target = stoi(s);
            result = target + (3-i);
            break;
        }
    }
    if(result%3 == 0 && result%5 == 0) cout << "FizzBuzz" << '\n';
    else if(result%3 == 0) cout << "Fizz" << '\n';
    else if(result%5 == 0) cout << "Buzz" << '\n';
    else cout << result << '\n';

    return 0;
}