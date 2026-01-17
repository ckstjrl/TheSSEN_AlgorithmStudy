// solved(BOJ1138 / S2): 한 줄로 서기
// 해결방법 : 그리디 키가 큰 사람부터 배치
// 메모 : O(N^2)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> info(N);
    for (int i = 0; i < N; i++) {
        cin >> info[i];
    }

    vector<int> line;

    // 키가 큰 사람부터 배치
    for (int height = N; height >= 1; height--) {
        int idx = info[height - 1];
        line.insert(line.begin() + idx, height);
    }

    for (int h : line) {
        cout << h << " ";
    }

    return 0;
}
