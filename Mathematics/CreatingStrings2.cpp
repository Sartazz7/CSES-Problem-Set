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
    string s;
    cin>>s;
    map<char,int> m;
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    ll ans=fact[s.size()];
    for(auto x:m){
        ans=(ans*modInv(fact[x.second],mod))%mod;
    }
    cout<<ans<<'\n';
}