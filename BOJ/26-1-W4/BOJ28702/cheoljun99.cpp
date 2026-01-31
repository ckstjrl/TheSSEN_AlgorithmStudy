//solved(BOJ28702 / S1): FizzBuzz

#include <bits/stdc++.h>

using namespace std;

bool isNumber(string str) {
    for (char c : str) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

int main() {
    vector<string>vec(3);
    int temp;
    int count;
    for (int i = 0; i < 3; ++i) {
        cin >> vec[i];
        if (isNumber(vec[i])) {
            temp = stoi(vec[i]);
            count = i;
        }
    }
    temp = temp + 3 - count;
    if (temp % 5 == 0 && temp % 3 ==0) {
        cout << "FizzBuzz" << endl;
    }
    else if (temp % 5 == 0 && temp % 3 != 0) {
        cout << "Buzz" << endl;
    }
    else if (temp % 5 != 0 && temp % 3 == 0) {
        cout << "Fizz" << endl;
    }
    else {
        cout << temp<<endl;
    }
}