#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll *f;
ll n,k;
ll *a;

void insertFreq(int mask[]){
    ll x=1;
    int num=0;
    for(int i=0; i<k; i++){
        if(mask[i]==1){
            num++;
            if(n/a[i]>=x)x*=a[i];
            else return;
        }
    }
    f[num]+=n/x;
}

void calcFreq(int i, int mask[]){
    if(i==k){
        insertFreq(mask);
        return;
    }
    mask[i]=0;
    calcFreq(i+1,mask);
    mask[i]=1;
    calcFreq(i+1,mask);
}

int main(){
    cin>>n>>k;
    f=new ll [k+1];
    a=new ll [k];
    for(int i=0; i<k; i++){
        cin>>a[i];
        f[i]=0;
    }
    f[k]=0;
    int mask[k];
    calcFreq(0,mask);
    ll ans=0;
    int p=1;
    for(int i=1; i<=k; i++){
        ans+=p*f[i];
        p*=-1;
    }
    cout<<ans<<"\n";
}