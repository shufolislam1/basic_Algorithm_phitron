#include<bits/stdc++.h>
using namespace std;

// const int N = 1e5+5;
// vector<int> adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    int e;
    cin>>e;
    for(int i=1;i<=e;i++){
        int a,b;
        cin>>a>>b;
        pq.push({a,b});
        // adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        cout<<p.first<<" "<<p.second<<endl; 
    }
    return 0;
}