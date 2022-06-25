#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int a[n+1],b[n+1];
    for(int i=1; i<n+1; i++){
        cin>>a[i];
    }
    for(int i=1; i<n+1; i++){
        cin>>b[i];
    }
    int d[2][x+1];
    for(int i=0; i<x+1; i++){
        d[0][i]=0;
    }
    for(int i=0; i<2; i++){
        d[i][0]=0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<x+1; j++){
            d[i%2][j]=d[(i-1)%2][j];
            if(j>=a[i])d[i%2][j]=max(d[i%2][j],d[(i-1)%2][j-a[i]]+b[i]);
        }
    }
    cout<<d[n%2][x]<<"\n";
    return 0;
}