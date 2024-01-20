#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;
    ll p=5;
    ll ans=0;
    while(n/p!=0){
        ans+=n/p;
        p=p*5;
    }
    cout<<ans<<'\n';
}