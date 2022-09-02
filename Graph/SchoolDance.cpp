#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int n,m,k;
set<int> *adj;
bool *vis;
 
bool dfs(int k){
    if(vis[k])return false;
    if(k==n+m+1)return true;
    vis[k]=true;
    for(auto x:adj[k]){
        if(dfs(x)){
            adj[x].insert(k);
            adj[k].erase(x);
            return true;
        }
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    adj=new set<int> [n+m+2];
    vis=new bool [n+m+2];
    for(int i=0; i<n+m+2; i++){
        vis[i]=false;
    }
    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b+n);
    }
    for(int i=1; i<n+1; i++){
        adj[0].insert(i);
    }
    for(int i=n+1; i<n+m+1; i++){
        adj[i].insert(n+m+1);
    }
    int ans=0;
    while(dfs(0)){
        ans++;
        for(int i=0; i<n+m+2; i++){
            vis[i]=false;
        }
    }
    cout<<ans<<"\n";
    for(int i=n+1; i<m+n+1; i++){
        for(auto x:adj[i]){
            if(x<n+1)cout<<x<<" "<<i-n<<"\n";
        }
    }
}