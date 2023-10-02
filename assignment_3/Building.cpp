#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int pSize[N];

void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        pSize[i] = 1;
    }
}

int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int A = dsu_find(a);
    int B = dsu_find(b);
    if (A != B) {
        if (pSize[A] > pSize[B]) {
            parent[B] = A;
            pSize[A] += pSize[B];
        } else {
            parent[A] = B;
            pSize[B] += pSize[A];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    long long total = 0; 

    for (Edge val : v) {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            continue;

        ans.push_back(val);
        dsu_union(a, b);

        total += w; 
    }

    int leader = dsu_find(1);
    for (int i = 2; i <= n; i++) {
        if (dsu_find(i) != leader) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total << endl; 
    
    return 0;
}
