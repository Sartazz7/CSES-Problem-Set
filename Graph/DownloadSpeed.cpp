#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n,m;
map<int,ll> *adj;
bool *vis;

ll dfs(int k, ll w){
    // cout<<k<<"\n";
    if(w<=0)return 0;
    if(vis[k])return 0;
    if(k==n)return w;
    vis[k]=true;
    for(auto x:adj[k]){
        ll f=dfs(x.first,min(x.second,w));
        if(f>0){
            adj[k][x.first]-=f;
            adj[x.first][k]+=f;
            return f;
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    adj=new map<int,ll> [n+1];
    vis=new bool [n+1];
    for(int i=0; i<m; i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a][b]+=c;
    }
    ll ans=0;
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    ll k=dfs(1,INT_MAX);
    while(k>0){
        ans+=k;
        // cout<<k<<"\n";
        for(int i=0; i<n+1; i++){
            vis[i]=false;
        }
        k=dfs(1,INT_MAX);
    }
    cout<<ans<<"\n";
}