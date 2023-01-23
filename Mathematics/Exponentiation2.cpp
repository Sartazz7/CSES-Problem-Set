#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll power(ll a, ll b, int mod){
    ll p=a;
    ll p1=1;
    while(b>0){
        if(b%2==1){
            p1=(p1*p)%mod;
        }
        b/=2;
        p=(p*p)%mod;
    }
    return p1;
}

int main(){
    int t;
    cin>>t;
    int mod=1000000007;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        b=power(b,c,mod-1);
        cout<<power(a,b,mod)<<"\n";
    }
}