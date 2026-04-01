#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> m1, vector<vector<int>> m2,int N) {
    vector<vector<int>> res(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i][j] += m1[i][k] * m2[k][j]; 
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long B;
    cin >> N >> B;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> I(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        I[i][i] = 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    while (B != 0) {
        int rem = B % 2;
        if (rem) {
            I = multiply(I, A, N);
        }
        int quo = B / 2;
        if (quo) {
            A = multiply(A, A, N);
        }
        B /= 2;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << I[i][j] <<' ';
        }
        cout << '\n';
    }
    return 0;
}