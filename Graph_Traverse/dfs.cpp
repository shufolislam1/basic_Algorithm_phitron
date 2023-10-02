#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool visited[N];
vector<int> adj[N];

void dfs(int src){
    visited[src] = true;
    cout<<src<<endl;
    for(int child:adj[src]){
        if(!visited[child]){
            dfs(child);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    
    return 0;
}