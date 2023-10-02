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

        int dp[tMark + 1];
        dp[0] = 0;

        for (int i = 1; i <= tMark; i++)
        {
            dp[i] = INT_MAX;
        }

        for (int i = 1; i <= tMark; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[j] <= i)
                {
                    int sp = dp[i - arr[j]];
                    if (sp != INT_MAX && sp + 1 < dp[i])
                    {
                        dp[i] = sp + 1;
                    }
                }
            }
        }

        if (dp[tMark] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[tMark] << endl;
        }
    }

    return 0;
}
