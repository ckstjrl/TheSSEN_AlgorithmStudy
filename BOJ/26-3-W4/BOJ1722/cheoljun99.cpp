#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long factorial[21];
    factorial[0] = 1;
    for (int i = 1; i < 21; ++i) {
        factorial[i] = i * factorial[i - 1];
    }
    int N;
    cin >> N;
    int flag;
    cin >> flag;
    if (flag == 1) {
        long long num;
        cin >> num;
        num -= 1;
        vector<int> temp(N, 0);
        vector<int> result;
        for (int i = 0; i < N; ++i) {;
            temp[i] = i + 1;
        }
        while (!temp.empty()) {
            int idx = num /factorial[temp.size()-1];
            num = num % factorial[temp.size()-1];
            result.push_back(temp[idx]);
            temp.erase(temp.begin() + idx);
        }
        for (int x : result) {
            cout << x << ' ';
        }
    }
    else {
        vector<int>listArr(N, 0);
        vector<int> temp(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> listArr[i];
            temp[i] = i + 1;
        }
        long long result = 0;
        for (int i = 0; i < N; ++i) {
            int idx = find(temp.begin(), temp.end(), listArr[i]) - temp.begin();
            result += idx * factorial[temp.size() - 1];
            temp.erase(temp.begin() + idx);
        }
        ++result;
        cout << result;
    }
    return 0;
}