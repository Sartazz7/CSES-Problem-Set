#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define INF (ll)1e15

int main(){
    int n,m;
    cin>>n>>m;
    ll a[n+1][n+1];
    vector<ll> v[n+1],w[n+1];
    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(y);
        w[x].push_back(-z);
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            a[i][j]=INF;
        }
        a[1][i]=0;
    }
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=0; j<v[i].size(); j++){
                if(a[i][k-1]!=INF)a[v[i][j]][k]=min(a[v[i][j]][k-1],a[i][k-1]+w[i][j]);
                else a[v[i][j]][k]=a[v[i][j]][k-1];
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1; i<n+1; i++){
        if(a[i][n-1]!=a[i][n]){
            cout<<-1<<"\n";
            return 0;
        }
    }
    cout<<-a[n][n]<<"\n";
    return 0;
}