#include<bits/stdc++.h>

using namespace std;

#define ll long

int n,m;
vector<int> *v;
int *d;
bool *vis;
int t;

void dfs(int k){
    vis[k]=true;
    for(int i=0; i<v[k].size(); i++){
        if(!vis[v[k][i]])dfs(v[k][i]);
    }
    d[k]=t;
    t++;
}

int main(){
    cin>>n>>m;
    v = new vector<int> [n+1];
    d = new int [n+1];
    vis = new bool [n+1];
    t = 0;
    for(int i=0; i<n+1; i++){
        vis[i]=false;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    dfs(1);
    vector<vector<int>> v1;
    for(int i=1; i<n+1; i++){
        v1.push_back({d[i],i});
    }
    sort(v1.begin(),v1.end(),greater<vector<int>>());
    int p[n+1];
    int dist[n+1];
    for(int i=0; i<n+1; i++){
        dist[i]=-1;
    }
    p[1]=0;
    dist[1]=0;
    for(int i=0; i<n; i++){
        int u=v1[i][1];
        if(dist[u]==-1)break;
        for(auto w:v[u]){
            if(dist[w]<dist[u]+1){
                dist[w]=dist[u]+1;
                p[w]=u;
            }
        }
    }
    if(dist[n]==-1)cout<<"IMPOSSIBLE\n";
    else {
        vector<int> v2;
        int k=n;
        while(k!=0){
            v2.push_back(k);
            k=p[k];
        }
        cout<<dist[n]+1<<"\n";
        for(int i=v2.size()-1; i>=0; i--){
            cout<<v2[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}