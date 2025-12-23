#include <iostream>
using namespace std;

int main() {
    int t, floor, room;

    cin >> t;
    int people[15][14] = {0};

    for (int p = 0; p < t; ++p) {
        cin >> floor >> room;
        for (int i = 0; i <= floor; ++i) {
            for (int j = 1; j <= room; ++j) {
                int sum = 0;
                if (i == 0) people[i][j] = j;
                else {
                    for (int k = 1; k <= j; ++k) {
                        sum += people[i - 1][k];
                    }
                    people[i][j] = sum;
                }
            }
        }
        cout << people[floor][room] << endl;
    }
}