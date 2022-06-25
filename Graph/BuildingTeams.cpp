#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool bfs(vector<int> adj[], vector<int> &side, int k){
    queue<int> q;
    q.push(k);
    side[k]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(side[v]==-1){
                if(side[u]==1)side[v]=2;
                else side[v]=1;
                q.push(v);
            }
            else {
                if(side[v]==side[u])return false;
            }
        }
    }
    return true;
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
    vector<int> side(n+1,-1);
    side[0]=0;
    for(int i=1; i<n+1; i++){
        if(side[i]==-1){
            bool k=bfs(v,side,i);
            if(!k)return {-1};
        }
    }
    return side;
}

int main(){
    vector<int> v=ans();
    if(v[0]==-1)cout<<"IMPOSSIBLE\n";
    else {
        for(int i=1; i<v.size(); i++){
            cout<<v[i]<<" "<<" ";
        }
        cout<<"\n";
    }
    return 0;
}