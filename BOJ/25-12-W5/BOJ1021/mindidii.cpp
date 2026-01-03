#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> pick_list(M);
    for (int i = 0; i < M; i++) {
        cin >> pick_list[i];
    }

    deque<int> q;
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        auto it = find(q.begin(), q.end(), pick_list[i]);
        int index = distance(q.begin(), it);

        if (index <= q.size() / 2) {
            for (int k = 0; k < index; k++) {
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
        } else {
            for (int k = 0; k < q.size() - index; k++) {
                q.push_front(q.back());
                q.pop_back();
                cnt++;
            }
        }

        q.pop_front();
    }

    cout << cnt << endl;
    return 0;
}