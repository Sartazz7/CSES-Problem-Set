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

vector<int> coveredAll(vector<int> v[], int n){
    bool vis[n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    dfs(v,1,vis);
    for(int i=1; i<n+1; i++){
        if(!vis[i])return {0,1,i};
    }
    return {1};
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v1[n+1],v2[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    vector<int> v=coveredAll(v1,n);
    if(v[0]==0){
        cout<<"NO\n";
        cout<<v[1]<<" "<<v[2]<<"\n";
        return 0;
    }
    v=coveredAll(v2,n);
    if(v[0]==0){
        cout<<"NO\n";
        cout<<v[2]<<" "<<v[1]<<"\n";
        return 0;
    }
    cout<<"YES\n";
}