#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1; i<n+1; i++){
        a[i][1]=i-1;
    }
    for(int i=1; i<m+1; i++){
        a[1][i]=i-1;
    }
    for(int i=2; i<n+1; i++){
        for(int j=2; j<m+1; j++){
            int b=INT_MAX;
            for(int k=1; k<i; k++){
                b=min(b,a[k][j]+a[i-k][j]);
            }
            for(int k=1; k<j; k++){
                b=min(b,a[i][k]+a[i][j-k]);
            }
            a[i][j]=b+1;
            if(i==j)a[i][j]=0;
        }
    }
    cout<<a[n][m]<<"\n";
    return 0;
}