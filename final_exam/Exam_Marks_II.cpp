#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int tMark = 1000 - M;

        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        bool dp[N + 1][tMark + 1];
        dp[0][0] = true;

        for (int i = 1; i <= tMark; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= tMark; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - arr[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[N][tMark])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
