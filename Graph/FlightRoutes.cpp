#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > v[n+1];
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>> > q;
    vector<ll> dist[n+1];
    q.push({0,1});
    while(dist[n].size()<k){
        ll u=q.top()[1];
        ll d=q.top()[0];
        while(dist[u].size()>=k){
            q.pop();
            u=q.top()[1];
            d=q.top()[0];
        }
        q.pop();
        dist[u].push_back(d);
        for(int i=0; i<v[u].size(); i++){
            q.push({d+v[u][i][1],v[u][i][0]});
        }
    }
    for(int i=0; i<k; i++){
        cout<<dist[n][i]<<" ";
    }
    cout<<"\n";
}