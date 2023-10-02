#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e7;

int main()
{
    int n, e;
    cin >> n >> e;

    long long dis[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], w);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     dis[i][i] = 0;
    // }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }

    return 0;
}
