#include<bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(vector<int> v[], int k, bool vis[]){
    vis[k]=true;
    for(int i=0; i<v[k].size(); i++){
        if(!vis[v[k][i]]){
            dfs(v,v[k][i],vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<vector<int> > v1;
    bool vis[n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    dfs(v,1,vis);
    for(int i=2; i<n+1; i++){
        if(!vis[i]){
            v1.push_back({1,i});
            dfs(v,i,vis);
        }
    }
    cout<<v1.size()<<"\n";
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i][0]<<" "<<v1[i][1]<<"\n";
    }
    return 0;
}