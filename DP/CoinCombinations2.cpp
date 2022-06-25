#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int a[n+1];
    int mod=1000000007;
    for(int i=1; i<n+1; i++){
        cin>>a[i];
    }
    int *b[n+1];
    for(int i=0; i<n+1; i++){
        b[i] = new int [x+1];
        b[i][0]=1;
    }
    for(int i=1; i<x+1; i++){
        b[0][i]=0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<x+1; j++){
            b[i][j]=b[i-1][j];
            if(j>=a[i])b[i][j]=(b[i][j]+b[i][j-a[i]])%mod;
            //cout<<i<<" "<<j<<" "<<b[i][j]<<"\n";
        }
    }
    cout<<b[n][x]<<"\n";
    return 0;
}