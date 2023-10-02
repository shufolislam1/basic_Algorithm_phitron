#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, W;
        cin >> N >> W;

        vector<int> w(N), v(N);
        for (int i = 0; i < N; i++)
        {
            cin >> w[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        int dp[N + 1][W + 1];

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (w[i - 1] <= j)
                {
                    dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout << dp[N][W] << endl;
    }

    return 0;
}
