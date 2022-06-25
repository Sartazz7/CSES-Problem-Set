#include<bits/stdc++.h>

using namespace std;

#define ll long long

int dfs(vector<int> adj[], int u, bool vis[], int p[]){
    vis[u]=true;
    for(auto v:adj[u]){
        if(v==p[u])continue;
        p[v]=u;
        if(vis[v])return u;
        int k=dfs(adj,v,vis,p);
        if(k!=-1)return k;
    }
    return -1;
}

vector<int> createCycle(int u, int p[]){
    vector<int> v1;
    int k=u;
    while(k!=p[u]){
        v1.push_back(u);
        u=p[u];
    }
    v1.push_back(u);
    v1.push_back(p[u]);
    return v1;
}

vector<int> ans(){
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int p[n+1];
    bool vis[n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=false;
        p[i]=-1;
    }
    for(int i=1; i<n+1; i++){
        if(!vis[i]){
            int k=dfs(v,i,vis,p);
            if(k!=-1)return createCycle(k,p);
        }
    }
    return {-1};
}

int main(){
    vector<int> v1=ans();
    if(v1[0]==-1)cout<<"IMPOSSIBLE\n";
    else {
        cout<<v1.size()<<"\n";
        for(int i=0; i<v1.size(); i++){
            cout<<v1[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}