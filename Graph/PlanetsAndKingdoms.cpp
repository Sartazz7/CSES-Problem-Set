#include<bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(vector<int> v[], int k, int vis[], int m){
    vis[k]=m;
    for(int i=0; i<v[k].size(); i++){
        if(vis[v[k][i]]==0){
            dfs(v,v[k][i],vis,m);
        }
    }
}

void dfs2(vector<int> v[], int k, int vis[], stack<int> &s){
    vis[k]=1;
    for(int i=0; i<v[k].size(); i++){
        if(vis[v[k][i]]==0){
            dfs2(v,v[k][i],vis,s);
        }
    }
    s.push(k);
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
    int vis[n+1];
    for(int i=0; i<n+1; i++){
        vis[i]=0;
    }
    stack<int> s;
    for(int i=1; i<n+1; i++){
        if(vis[i]==0){
            dfs2(v1,i,vis,s);
        }
    }
    for(int i=0; i<n+1; i++){
        vis[i]=0;
    }
    int k=1;
    for(int i=1; i<n+1; i++){
        int x=s.top();
        s.pop();
        if(vis[x]==0){
            dfs(v2,x,vis,k);
            k++;
        }
    }
    cout<<k-1<<"\n";
    for(int i=1; i<n+1; i++){
        cout<<vis[i]<<" ";
    }
    cout<<"\n";
}