#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll n=max(x,y)-1;
        n=n*n+n+1;
        if(x>y){
            if(x%2==0)n+=(x-y);
            else n-=(x-y);
        }
        else{
            if(y%2==1)n+=(y-x);
            else n-=(y-x);
        }
        cout<<n<<'\n';
    }
}