#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    int count = 0;
    for (int i = 9; i >= 2; --i) {
        while (n % i == 0) {
            n /= i;
            count++;
        }
    }

    if (n > 1) {
        cout << -1 << "\n";
    } else {
        cout << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}