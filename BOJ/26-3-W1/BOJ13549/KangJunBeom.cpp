    /*
        숨바꼭질 3
        그래프
        체감 난이도 : 보통
    */

    #include <bits/stdc++.h>
    using namespace std;

    int dist[100001];

    int main(){
        int sister, subin;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        fill(dist, dist+100001, INT_MAX);

        cin >> subin >> sister;
        dist[subin] = 0;
        pq.push({0,subin});

        while(!pq.empty()){
            int curr = pq.top().second;
            int cost = pq.top().first;
            if(curr == sister) break;
            pq.pop();

            if(dist[curr] < cost) continue;

            int next_pos[3] = {curr * 2, curr + 1, curr - 1};
            int weight[3] = {0, 1, 1}; // 순간이동은 0초, 걷기는 1초

            for (int i = 0; i < 3; i++) {
                int next = next_pos[i];
                int next_cost = cost + weight[i];

                // [중요 조건 1] 지도를 벗어나지 않는가? (0 ~ 100,000)
                if (next >= 0 && next <= 100000) {
                    // [중요 조건 2] 이 경로가 기존에 찾은 경로보다 더 빠른가?
                    if (next_cost < dist[next]) {
                        dist[next] = next_cost; // 거리 갱신
                        pq.push({next_cost, next}); // 우선순위 큐에 삽입
                    }
                }
            }
        }

        cout << dist[sister];
    }