#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define INF (ll)1e18

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    ll a[n+1][n+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            a[i][j]=INF;
            if(i==j)a[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=min(a[x][y],(ll)z);
        a[y][x]=min(a[y][x],(ll)z);
    }
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=i+1; j<n+1; j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                a[j][i]=a[i][j];
            }
        }
    }
    while(q--){
        int b,c;
        cin>>b>>c;
        if(a[b][c]==INF)cout<<-1<<"\n";
        else cout<<a[b][c]<<"\n";
    }
    return 0;
}