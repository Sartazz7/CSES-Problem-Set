#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n,m;
vector<vector<int>> *adj;
bool *vis;

bool dfs(int k){
    if(vis[k])return false;
    if(k==n)return true;
    vis[k]=true;
    for(int i=0; i<adj[k].size(); i++){
        if(dfs(adj[k][i][0])){
            adj[adj[k][i][0]].push_back({k,1-adj[k][i][1]});
            adj[k].erase(adj[k].begin()+i);
            return true;
        }
    }
    return false;
}

vector<int> dfs1(int k){
    if(k==1)return {1};
    for(int i=0; i<adj[k].size(); i++){
        if(adj[k][i][1]==1){
            adj[k][i][1]=0;
            vector<int> v1=dfs1(adj[k][i][0]);
            v1.push_back(k);
            return v1;
        }
    }
    return {};
}

int main(){
    cin>>n>>m;
    adj=new vector<vector<int>> [n+1];
    vis=new bool [n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,0});
    }
    int ans=0;
    while(dfs(1)){
        ans++;
        for(int i=0; i<n+1; i++){
            vis[i]=false;
        }
    }
    vector<vector<int>> v;
    for(int i=0; i<adj[n].size(); i++){
        if(adj[n][i][1]==1){
            vector<int> v1=dfs1(adj[n][i][0]);
            v1.push_back(n);
            v.push_back(v1);
        }
    }
    cout<<ans<<"\n";
    for(auto v1:v){
        cout<<v1.size()<<"\n";
        for(auto e:v1){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
}