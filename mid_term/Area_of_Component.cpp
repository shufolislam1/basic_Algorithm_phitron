#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
bool visited[N][N];
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
char a[N][N];
int cnt;

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m && a[ci][cj] == '.')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> parent = path[i];
        int pi = parent.first;
        int pj = parent.second;

        int ci = pi + si;
        int cj = pj + sj;
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    int mn = INT_MAX;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if (mn == INT_MAX)
        cout << "-1" << endl;
    else
        cout << mn << endl;
    return 0;
}