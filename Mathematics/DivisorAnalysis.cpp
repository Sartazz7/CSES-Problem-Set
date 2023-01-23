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

ll modInv(ll a, int mod){
    return power(a,mod-2,mod);
}

int main(){
    int n;
    cin>>n;
    int mod=1000000007;
    vector<vector<ll>> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    ll num=1;
    ll num1=1;
    bool div2=false;
    for(int i=0; i<n; i++){
        num=(num*(v[i][1]+1))%mod;
        if(v[i][1]%2==1 && !div2){
            div2=true;
            num1=(num1*(v[i][1]+1)/2)%(mod-1);
        }
        else num1=(num1*(v[i][1]+1))%(mod-1);
    }
    ll sum=1;
    for(int i=0; i<n; i++){
        ll f=power(v[i][0],v[i][1]+1,mod);
        f=(f-1+mod)%mod;
        f=(f*modInv(v[i][0]-1,mod))%mod;
        // cout<<f<<"\n";
        sum=(sum*f)%mod;
    }
    ll prd=1;
    for(int i=0; i<n; i++){
        if(div2)prd=(prd*power(v[i][0],(v[i][1]*num1)%(mod-1),mod))%mod;
        else prd=(prd*power(v[i][0],(v[i][1]*num1/2)%(mod-1),mod))%mod;
    }
    // cout<<num1<<"\n";
    cout<<num<<" "<<sum<<" "<<prd<<"\n";
}