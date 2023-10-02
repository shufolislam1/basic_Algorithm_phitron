#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int s, vector<int> &result)
{
    visited[s] = true;
    result.push_back(s);
    for (int v : adj[s])
    {
        if (!visited[v])
        {
            dfs(v, result);
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    int source_node;
    cin >> source_node;

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    vector<int> result;
    dfs(source_node, result);

    int count = result.size() - 1;

    cout << count << endl;

    return 0;
}
