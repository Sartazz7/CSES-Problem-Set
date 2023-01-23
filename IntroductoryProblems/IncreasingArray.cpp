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
    ll val=a[0];
    ll ans=0;
    for(int i=1; i<n; i++){
        val=max(val,a[i]);
        ans+=val-a[i];
    }
    cout<<ans<<"\n";
}