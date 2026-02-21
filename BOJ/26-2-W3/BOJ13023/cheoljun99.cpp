//solved(BOJ13023/ G5): ABCDE
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>>list(N, vector<int>());
    vector<bool>visited(N, false);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    stack<tuple<int,int,int>>st;
    for (int i = 0; i < N; ++i) {
        st.push({ i,1,0 });
        visited[i] = true;
        while(!st.empty()){
            int cur_idx = get<0>(st.top());
            int cur_depth = get<1>(st.top());
            if (cur_depth ==5) {
                cout << 1;
                return 0;
            }
            bool pushed = false;
            for (; get<2>(st.top()) < list[cur_idx].size(); ++get<2>(st.top())) {
                int next_idx = list[cur_idx][get<2>(st.top())];
                int next_depth = cur_depth + 1;
                if (visited[next_idx] == false) {
                    ++get<2>(st.top());
                    st.push({ next_idx, next_depth, 0 });
                    visited[next_idx] = true;
                    pushed = true;
                    break;
                }
            }
            if (!pushed) {
                st.pop();
                visited[cur_idx] = false;
            }
        }
    }
    cout << 0;
    return 0;
}