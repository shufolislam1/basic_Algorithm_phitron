#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] =true;
    level[src] =0;

    while (!q.empty())
    {
        int parent  = q.front();
        q.pop();
        

        for(int child:adj[parent]){
            if(!visited[child]){
                cout<<parent+child<<endl;
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
    
}
int main(){
    int  n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": "<<level[i]<<endl;
    // }
    
    return 0;
}