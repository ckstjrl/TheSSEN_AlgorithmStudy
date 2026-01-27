#include <bits/stdc++.h>
using namespace std;

int divide(int A, int B) {
    if (A % B == 0)
        return B;
    else
        return divide(B, A % B);
}

int main() {
	int a, b;
	cin >> a >> b;

    int GCD = divide(a, b);
    cout << GCD << "\n" << a * b / GCD;

}