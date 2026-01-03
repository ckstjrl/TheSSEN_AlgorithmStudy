#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    while (cin >> input && input != "*") {
        int n = input.size();
        bool flag = true;

        for (int d = 1; d <= n - 1; ++d) {
            set<string> seen;
            for (int i = 0; i + d < n; ++i) {
                string tmp = "";
                tmp += input[i];
                tmp += input[i + d];

                if (seen.find(tmp) != seen.end()) {
                    flag = false;
                    break;
                }
                seen.insert(tmp);
            }
            if (!flag) break;
        }

        if (flag) cout << input << " is surprising.\n";
        else cout << input << " is NOT surprising.\n";
    }

    return 0;
}