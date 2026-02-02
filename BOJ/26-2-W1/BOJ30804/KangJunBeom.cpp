#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> fruits(n);
    for (int i = 0; i < n; ++i) {
        cin >> fruits[i];
    }

    int count[10] = {0};
    int l = 0, r = 0;
    int max_length = 0;
    int type_fruits = 0;

    for (r = 0; r < n; ++r) {
        if (count[fruits[r]] == 0) {
            type_fruits++;
        }
        count[fruits[r]]++;

        while (type_fruits > 2) {
            count[fruits[l]]--;
            if (count[fruits[l]] == 0) {
                type_fruits--;
            }
            l++;
        }

        max_length = max(max_length, r - l + 1);
    }

    cout << max_length << "\n";

    return 0;
}