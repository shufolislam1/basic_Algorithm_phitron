#include <bits/stdc++.h>
using namespace std;

bool visited[105][105];
int dist[105][105];
int n, m;
int si, sj, di, dj;
vector<pair<int, int>> path = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            pair<int, int> p = path[i];

            int ci = pi + p.first;
            int cj = pj + p.second;

            if (isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
                dist[ci][cj] = dist[pi][pj] + 1;

                if(ci == di && cj == dj){
                    return;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        
        cin >> n >> m;
        cin >> si >> sj;
        cin >> di >> dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
                dist[i][j] = -1;
            }
        }

        bfs(si, sj);
        if (dist[di][dj] != -1)
        {
            cout << dist[di][dj] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}