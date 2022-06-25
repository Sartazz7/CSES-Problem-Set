#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll sum=0;
    ll maxsum=-1e18;
    for(int i=0; i<n; i++){
        sum+=a[i];
        maxsum=max(maxsum,sum);
        if(sum<0)sum=0;
    }
    cout<<maxsum<<"\n";
    return 0;
}