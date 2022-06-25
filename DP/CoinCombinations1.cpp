#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    int mod=1000000007;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int *b;
    b=new int [x+1];
    b[0]=1;
    for(int i=1; i<x+1; i++){
        b[i]=0;
        for(int j=0; j<n; j++){
            if(a[j]<=i)b[i]=(b[i]+b[i-a[j]])%mod;
        }
    }
    cout<<b[x]<<"\n";
    return 0;
}