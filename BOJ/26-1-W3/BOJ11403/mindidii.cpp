#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int adj[100][100];
int result[100][100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    
    vector<bool> visited(N, false);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next = 0; next < N; next++) {
            if (adj[curr][next] == 1 && !visited[next]) {
                visited[next] = true;
                result[start][next] = 1; 
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        bfs(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}