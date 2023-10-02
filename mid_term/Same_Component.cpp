#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
bool visited[N][N];
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
char a[N][N];

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m && a[ci][cj] == '.')
        return true;
    else
        return false;
}

void bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second;

            if (isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
    if (visited[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;

    int di, dj;
    cin >> di >> dj;
    cin >> si >> sj;
    bfs(si, sj, di, dj);
    return 0;
}