#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> bfs(vector<int> adj[], int n){
    queue<int> q;
    q.push(1);
    int p[n+1];
    for(int i=0; i<n+1; i++){
        p[i]=-1;
    }
    p[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(p[v]==-1){
                p[v]=u;
                q.push(v);
            }
        }
    }
    if(p[n]==-1)return {-1};
    vector<int> v1;
    int k=n;
    while(k!=1){
        v1.push_back(k);
        k=p[k];
    }
    v1.push_back(1);
    return v1;
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
    vector<int> v1=bfs(v,n);
    if(v1[0]==-1)cout<<"IMPOSSIBLE\n";
    else{
        cout<<v1.size()<<"\n";
        for(int i=v1.size()-1; i>=0; i--){
            cout<<v1[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}