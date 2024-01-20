#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;
    if(n%4!=0 && n%4!=3){
        cout<<"NO\n";
        return 0;
    }
    vector<ll> v1, v2;
    ll k=n;
    ll sum=0;
    while(k>0){
        if(sum+k>n*(n+1)/4)v2.push_back(k);
        else {
            v1.push_back(k);
            sum+=k;
        }
        k--;
    }
    cout<<"YES\n";
    cout<<v1.size()<<"\n";
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<'\n';
    cout<<v2.size()<<"\n";
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    cout<<'\n';
}