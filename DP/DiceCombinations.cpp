#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    ll mod=1000000007;
    ll a[n+7];
    a[0]=0;
    for(int i=1; i<7; i++){
        a[i]=1;
        for(int j=1; j<i+1; j++){
            a[i]+=a[i-j];
        }
    }
    for(int i=7; i<n+1; i++){
        a[i]=0;
        for(int j=1; j<7; j++){
            a[i]+=a[i-j];
            a[i]=(a[i]%mod);
        }
    }
    cout<<a[n]<<"\n";
    return 0;
}