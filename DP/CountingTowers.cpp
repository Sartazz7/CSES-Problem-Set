#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll ans(){
    int n;
    cin>>n;
    ll a[n+1],s[n+1];
    a[0]=0;
    s[0]=0;
    ll k=1;
    int mod=1000000007;
    for(int i=1; i<n+1; i++){
        k=(k*2)%mod;
        a[i]=(s[i-1]+k+1)%mod;
        s[i]=(s[i-1]+a[i])%mod;
    }
    return a[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<ans()<<'\n';
    }
    return 0;
}