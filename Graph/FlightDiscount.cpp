#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v[2*n+1];
    vector<int> w[2*n+1];
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        w[a].push_back(c);
        v[n+a].push_back(n+b);
        w[n+a].push_back(c);
        v[a].push_back(n+b);
        w[a].push_back(c/2);
    }
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
    int s[2*n+1];
    ll dist[2*n+1];
    for(int i=2; i<2*n+1; i++){
        s[i]=0;
        dist[i]=(ll)1e18;
    }
    dist[1]=0;
    q.push({dist[1],1});
    for(int j=1; j<2*n+1; j++){
        int u=q.top()[1];
        while(s[u]==1){
            q.pop();
            u=q.top()[1];
        }
        q.pop();
        s[u]=1;
        if(u==2*n)break;
        for(int i=0; i<v[u].size(); i++){
            if(dist[v[u][i]]>dist[u]+w[u][i]){
                dist[v[u][i]]=dist[u]+w[u][i];
                q.push({dist[v[u][i]],v[u][i]});
            }
        }
    }
    cout<<dist[2*n]<<"\n";
    return 0;
}