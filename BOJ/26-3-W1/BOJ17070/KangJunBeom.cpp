    /*
        파이프 옮기기 1
        DP/그래프
        체감 난이도 : 보통
    */

    #include <iostream>
    using namespace std;

    int N;
    bool map[16][16];
    int ans[16][16][3];
    //열거형으로 가로, 대각, 세로 정의
    enum Pos {H = 0, D = 1, V = 2};

    void pipe()
    {
        ans[0][1][H] = 1;
        for (int j = 2; j < N; j++)
            if (!map[0][j])
                ans[0][j][H] = ans[0][j - 1][H];

        for (int i = 1; i < N; i++)
        {
            for (int j = 2; j < N; j++)
            {
                // 벽이 아닌 경우
                if (!map[i][j])
                {
                    //가로의 경우에는 이전 열의 가로 값 + 대각 값
                    ans[i][j][H] = ans[i][j - 1][H] + ans[i][j - 1][D];
                    //세로의 경우에는 이전 행의 세로 값 + 대각 값
                    ans[i][j][V] = ans[i - 1][j][D] + ans[i - 1][j][V];
                    //만약 세 공간이 모두 벽이 아닌 경우 이전 왼대각 값의 가로,세로,대각값을 더한 값
                    if (!map[i-1][j] && !map[i][j-1])
                        ans[i][j][D] = ans[i - 1][j - 1][H] + ans[i - 1][j - 1][D] + ans[i - 1][j - 1][V];
                }
            }
        }

        cout << ans[N - 1][N - 1][V] + ans[N - 1][N - 1][D] + ans[N - 1][N - 1][H];
    }


    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(NULL);

        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];

        pipe();

    }

