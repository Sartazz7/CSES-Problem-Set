#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int *b;
    b = new int [x+1];
    b[0]=0;
    for(int i=1; i<x+1; i++){
        int mincoin=INT_MAX;
        for(int j=0; j<n; j++){
            if(a[j]<=i){
                if(b[i-a[j]]!=-1)mincoin=min(mincoin,b[i-a[j]]);
            }
            else break;
        }
        // cout<<b[i]<<"\n";
        if(mincoin==INT_MAX)b[i]=-1;
        else b[i]=mincoin+1;
    }
    cout<<b[x]<<"\n";
    return 0;
}