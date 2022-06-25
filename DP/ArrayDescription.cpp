#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    ll a[m+1][n];
    ll mod=1000000007;
    for(int i=0; i<n; i++){
        int b;
        cin>>b;
        if(i==0){
            if(b==0){
                for(int j=1; j<m+1; j++){
                    a[j][i]=1;
                }
            }
            else {
                for(int j=1; j<m+1; j++){
                    a[j][i]=0;
                }
                a[b][i]=1;
            }
        }
        else {
            if(b==0){
                for(int j=1; j<m+1; j++){
                    a[j][i]=a[j][i-1];
                    if(j>1)a[j][i]+=a[j-1][i-1];
                    if(j<m)a[j][i]+=a[j+1][i-1];
                    a[j][i]=(a[j][i])%mod;
                }
            }
            else {
                for(int j=1; j<m+1; j++){
                    a[j][i]=0;
                }
                a[b][i]=a[b][i-1];
                if(b>1)a[b][i]+=a[b-1][i-1];
                if(b<m)a[b][i]+=a[b+1][i-1];
                a[b][i]=(a[b][i])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1; i<m+1; i++){
        ans=(ans+a[i][n-1])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}