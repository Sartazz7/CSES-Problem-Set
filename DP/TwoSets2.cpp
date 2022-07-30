#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    ll *a[n+1];
    ll mod=1000000007;
    for(int i=0; i<n+1; i++){
        a[i]=new ll [n*(n+1)/2+1];
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n*(n+1)/2+1; j++){
            a[i][j]=0;
        }
    }
    a[0][0]=1;
    for(int i=1; i<n+1; i++){
        for(int j=0; j<n*(n+1)/2+1; j++){
            if(j>=i)a[i][j]=(a[i-1][j]+a[i-1][j-i])%mod;
            else a[i][j]=a[i-1][j];
        }
    }
    if(n%4==0 || n%4==3){
        cout<<a[n][(n*(n+1)/4)]/2<<"\n";
    }
    else cout<<0<<"\n";
    return 0;
}