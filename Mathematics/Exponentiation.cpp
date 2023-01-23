#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    int mod=1000000007;
    while(t--){
        int a,b;
        cin>>a>>b;
        ll p=a;
        ll p1=1;
        while(b>0){
            if(b%2==1){
                p1=(p1*p)%mod;
            }
            b/=2;
            p=(p*p)%mod;
        }
        cout<<p1<<"\n";
    }
}