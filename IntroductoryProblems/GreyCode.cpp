#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    int k=1;
    for(int i=0; i<n; i++){
        k*=2;
    }
    int a[k][n];
    int p=1;
    for(int i=0; i<n; i++){
        int j=0, s=0;
        for(j=0; j<p; j++)a[j][i]=s;
        while(j<k-p){
            s=1-s;
            for(int t=0; t<2*p; t++){
                a[j][i]=s;
                j++;
            }
        }
        s=1-s;
        for(;j<k; j++)a[j][i]=s;
        p=2*p;
    }
    for(int i=0; i<k; i++){
        for(int j=n-1; j>=0; j--){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}