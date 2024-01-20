#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;
    ll p=1;
    ll mod=1000000007;
    for(int i=0; i<n; i++){
        p=(p*2)%mod;
    }
    cout<<p<<'\n';
}