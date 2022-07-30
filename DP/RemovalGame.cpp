#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll b[n][n],c[n][n],s[n];
    s[0]=a[0];
    for(int i=1; i<n; i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=0; i<n; i++){
        b[i][i]=a[i];
        c[i][i]=a[i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            int x=j,y=i+j;
            ll sum=s[y];
            if(x>0)sum-=s[x-1];
            b[x][y]=max(sum-c[x][y-1],sum-c[x+1][y]);
            c[x][y]=max(sum-b[x][y-1],sum-b[x+1][y]);
        }
    }
    cout<<b[0][n-1]<<"\n";
    return 0;
}