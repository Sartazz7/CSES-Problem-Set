#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    int mod=1000000007;
    ll a[n+1][m+1];
    for(int i=0; i<m+1; i++){
        a[0][i]=1;
    }
    for(int i=0; i<n+1; i++){
        a[i][0]=1;
    }
    for(int i=1; i<m+1; i++){
        a[1][i]=(i+1)%2;
    }
    for(int i=1; i<n+1; i++){
        a[i][1]=(i+1)%2;
    }
    for(int i=2; i<n+1; i++){
        for(int j=2; j<m+1; j++){
            a[i][j]=(a[i][j-1]*a[i-2][1]+a[i-2][j]*a[2][j-1]-a[i-2][j-1]*a[i-2][1]*a[2][j-1]+a[i-1][j]*a[1][j-2]+a[i][j-2]*a[i-1][2]-a[i-1][j-2]*a[1][j-2]*a[i-1][2])%mod;
            cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
        }
    }
    cout<<a[n][m]<<"\n";
    return 0;
}