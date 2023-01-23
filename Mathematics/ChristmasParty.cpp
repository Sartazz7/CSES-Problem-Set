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

int main(){
    int mod=1000000007;
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int n;
    cin>>n;
    ll p=fact[n];
    ll ans=0;
    for(int i=2; i<=n; i++){
        ans=(ans+p*modInv(fact[i],mod)+mod)%mod;
        p*=-1;
    }
    cout<<(ans+mod)%mod<<"\n";
}