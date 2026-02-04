// BOJ 2667. 단지번호붙이기 / S1
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> danji(N, vector<int>(N));
	vector<pair<int, int>> house_axis;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			danji[i][j] = s[j] - '0';
			if (danji[i][j] == 1) {
				house_axis.push_back({ i, j });
			}
		}
	}

	int DanjiCnt = 0;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	queue<pair<int, int>> q;
	vector<vector<int>> visited(N, vector<int>(N, 0));
	vector<int> house_ea;

	for (int i = 0; i < house_axis.size(); i++) {
		int cx = house_axis[i].first;
		int cy = house_axis[i].second;
		
        if (visited[cx][cy] != 0) continue;
		
        q.push({ cx, cy });
		visited[cx][cy] = 1;
		int house_cnt = 1;
		
        while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] != 0 || danji[nx][ny] != 1) continue;
				
                visited[nx][ny] = 1;
				q.push({ nx, ny });
				house_cnt++;
			}
		}
		house_ea.push_back(house_cnt);
		DanjiCnt++;
	}
	cout << DanjiCnt << "\n";
	
    sort(house_ea.begin(), house_ea.end());
	
    for (int e : house_ea) {
		cout << e << "\n";
	}
}

/*
BFS 활용
처음 이차원 배열을 input으로 받을 때 미리 1인 좌표들을 다른 배열에 저장
그 배열을 순환하면서 BFS를 진행
이 순환 for문 위에 단지 총 개수를 세는 변수 미리 선언
BFS 진행하는 내부에 단지 집 개수 세는 변수 선언
이 방법을 통해 단지의 총 수와 각 단지별 집의 수를 저장
단지별 집의 수는 배열 정렬 후 출력
*/