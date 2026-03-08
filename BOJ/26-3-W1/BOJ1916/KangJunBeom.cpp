    /*
        최소비용 구하기
        다익스트라 알고리즘
        체감 난이도 : 보통
    */

    #include <bits/stdc++.h>
    using namespace std;

    vector<pair<int, int>> graph[1001];
    int dist[1001];

    void Dijkstra(int start)
    {
        //초기값은 무한대로 설정함
        fill(dist, dist + 1001, INT_MAX);

        //최솟값은 계속 가장 위에 오도록 설정
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start });
        dist[start] = 0;
        
        while (!pq.empty())
        {
            int CurNode = pq.top().second;
            int CurCost = pq.top().first;
            pq.pop();

            if (dist[CurNode] < CurCost)
                continue; // 가지 치기
            
            // 인접한 도시들을 모두 탐색
            int Size = static_cast<int>(graph[CurNode].size());
            for (int i = 0; i < Size; ++i)
            {
                int NextNode = graph[CurNode][i].first;
                int NextCost = graph[CurNode][i].second + CurCost;

                if (dist[NextNode] > NextCost)
                {
                    pq.push({ NextCost, NextNode }); // 더 싼 경로 발견 후 큐에 삽입
                    dist[NextNode] = NextCost; // 최소 비용 테이블 업데이트
                }
            }
        }
    }

    int main()
    {
        int N, M;
        cin >> N;
        cin >> M;

        for (int i = 0; i < M; ++i)
        {
            int A, B, Cost;
            cin >> A >> B >> Cost;
            graph[A].push_back({ B, Cost });
        }

        int start, end;
        cin >> start >> end;

        Dijkstra(start);

        cout << dist[end];

        return 0;
    }