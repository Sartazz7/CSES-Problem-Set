#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1000005

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

ll modInv(ll a, int mod){
    return power(a,mod-2,mod);
}

ll fact[N];

ll nCr(ll n, ll r, int mod){
    ll ans=fact[n];
    ans=(ans*modInv(fact[r],mod))%mod;
    ans=(ans*modInv(fact[n-r],mod))%mod;
    return ans;
}

int main(){
    int mod=1000000007;
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int n;
    cin>>n;
    if(n%2==1)cout<<0<<"\n";
    else cout<<(nCr(n,n/2,mod)*modInv(n/2+1,mod))%mod<<"\n";
}