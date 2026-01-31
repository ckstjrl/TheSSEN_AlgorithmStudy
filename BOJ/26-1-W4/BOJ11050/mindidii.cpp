#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int upper = 1, lower = 1;
    int n, k; 
    cin >> n >> k;
    for (int i = k; i > 0; i--) {
        upper *= n;
        n--;
    }
    for (int i = k; k > 0; k--) {
        lower *= k;
    }
    cout << upper / lower;
 
}