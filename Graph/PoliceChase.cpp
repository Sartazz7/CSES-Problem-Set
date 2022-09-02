#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n,m;
map<int,int> *adj;
bool *vis;

bool dfs(int k){
    if(vis[k])return false;
    if(k==n)return true;
    vis[k]=true;
    for(auto x:adj[k]){
        if(x.second==0)continue;
        if(dfs(x.first)){
            adj[x.first][k]++;
            adj[k][x.first]--;
            return true;
        }
    }
    return false;
}

void dfs(int k, int s[]){
    if(s[k]==1)return;
    s[k]=1;
    for(auto x:adj[k]){
        if(x.second>0)dfs(x.first,s);
    }
}

int main(){
    cin>>n>>m;
    adj=new map<int,int> [n+1];
    vector<int> v[n+1];
    vis=new bool [n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert({b,1});
        adj[b].insert({a,1});
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans=0;
    while(dfs(1)){
        ans++;
        for(int i=0; i<n+1; i++){
            vis[i]=false;
        }
    }
    cout<<ans<<"\n";
    // for(int i=1; i<n+1; i++){
    //     for(auto x:adj[i]){
    //         cout<<i<<" "<<x.first<<" "<<x.second<<"\n";
    //     }
    // }
    int s[n+1];
    for(int i=0; i<n+1; i++){
        s[i]=0;
    }
    dfs(1,s);
    for(int i=1; i<n+1; i++){
        if(s[i]==1){
            for(int j=0; j<v[i].size(); j++){
                if(s[v[i][j]]==0)cout<<i<<" "<<v[i][j]<<"\n";
            }
            // cout<<i<<" ";
        }
    }
}