#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];

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

    int L;
    cin >> L;
    if (L >= 0 && L <= n)
    {
        int sizeOfL = adj[L].size();
        cout << sizeOfL << endl;
    }
    return 0;
}