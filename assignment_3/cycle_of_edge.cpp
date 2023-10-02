#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int pSize[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        pSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int A = dsu_find(a);
    int B = dsu_find(b);
    if (A != B)
    {
        if (pSize[A] > pSize[B])
        {
            parent[B] = A;
            pSize[A] += pSize[B];
        }
        else
        {
            parent[A] = B;
            pSize[B] += pSize[A];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    
    int ans = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        if (dsu_find(a) == dsu_find(b))
        {
            ans++;
        }
        else
        {
            dsu_union(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}