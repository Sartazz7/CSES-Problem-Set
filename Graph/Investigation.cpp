#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll> > v[n+1];
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    ll dist[n+1];
    int s[n+1];
    ll paths[n+1];
    int minheight[n+1],maxheight[n+1];
    ll mod=1000000007;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>> > q;
    for(int i=0; i<n+1; i++){
        dist[i]=(ll)1e18;
        s[i]=0;
        paths[i]=0;
        minheight[i]=n;
        maxheight[i]=0;
    }
    minheight[1]=0;
    maxheight[1]=0;
    paths[1]=1;
    s[1]=0;
    dist[1]=0;
    int taken=1;
    q.push({dist[1],1});
    while(taken<n){
        ll u=q.top()[1];
        while(s[u]==1){
            q.pop();
            u=q.top()[1];
        }
        s[u]=1;
        ll d=q.top()[0];
        q.pop();
        for(auto w:v[u]){
            if(dist[w[0]]>dist[u]+w[1]){
                dist[w[0]]=dist[u]+w[1];
                q.push({dist[w[0]],w[0]});
                minheight[w[0]]=minheight[u]+1;
                maxheight[w[0]]=maxheight[u]+1;
                paths[w[0]]=paths[u];
            }
            else if(dist[w[0]]==dist[u]+w[1]){
                minheight[w[0]]=min(minheight[w[0]],minheight[u]+1);
                maxheight[w[0]]=max(maxheight[w[0]],maxheight[u]+1);
                paths[w[0]]=(paths[w[0]]+paths[u])%mod;
            }
        }
        taken++;
    }
    cout<<dist[n]<<" "<<paths[n]<<" "<<minheight[n]<<" "<<maxheight[n]<<"\n";
    return 0;
}