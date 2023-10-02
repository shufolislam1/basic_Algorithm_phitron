#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dist[N];
vector<pair<int, int>> adj[N];

void dijkstra(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (auto child : adj[parent])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (dist[parent] + childCost < dist[childNode])
            {
                dist[childNode] = dist[parent] + childCost;
                q.push(childNode);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        dist[N] = INT_MAX;
    }

    return 0;
}