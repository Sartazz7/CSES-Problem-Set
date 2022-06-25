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
    sort(a,a+n);
    ll d=a[n/2];
    if(n%2==0)d=d=(a[n/2]+a[n/2-1])/2;
    ll sum=0;
    for(int i=0; i<n; i++){
        sum+=abs(a[i]-d);
    }
    cout<<sum<<"\n";
    return 0;
}