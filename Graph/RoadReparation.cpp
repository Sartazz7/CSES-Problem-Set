#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    vector<ll> w[n+1];
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    int s[n+1];
    for(int i=0; i<n+1; i++){
        s[i]=0;
    }
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
    q.push({0,1});
    ll ans=0;
    for(int i=0; i<n; i++){
        while(!q.empty() && s[q.top()[1]]==1)q.pop();
        if(q.empty()){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        int u=q.top()[1];
        s[u]=1;
        // cout<<u<<"\n";
        ans+=q.top()[0];
        for(int j=0; j<v[u].size(); j++){
            // cout<<w[u][j]<<" "<<v[u][j]<<"\n";
            q.push({w[u][j],v[u][j]});
        }
    }
    cout<<ans<<"\n";
}