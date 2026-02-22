#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2001];
bool is_visit[2001] = {false, };
bool is_possible = false;

void DFS(int node, int cnt) {
    if(cnt == 4) {
        is_possible = true;
        return;
    }

    is_visit[node] = true;

    for(int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if(is_visit[next_node] == false) {
            DFS(next_node, cnt+1);
            is_visit[next_node] = false;
        }
    }
}

int main() {

    int N = 0, M = 0;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {

        if(is_visit[i] == false) {
            DFS(i, 0);
            is_visit[i] = false;
        }

        if(is_possible) {
            cout << 1 << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
    return 0; 
}