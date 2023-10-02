#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> adj[N];
bool visited[N];


int bfs(int s)
{
    queue<int> q;
    int c = 0;

    q.push(s);
    visited[s] = true;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                c++;
            }
        }
    }
    return c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    for (int i = 0; i <= N; i++)
    {
        if (visited[i])
            continue;
        int result = bfs(i);
        if (result > 1)
            ans.push_back(result);
    }
    sort(ans.begin(), ans.end());
    for (int res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
