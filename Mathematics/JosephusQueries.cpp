#include<bits/stdc++.h>

using namespace std;

#define ll long long

int person(int n, int k, int s){
    if(s==1){
        if(k<=(n+1)/2)return 2*k-1;
        return 2*person(n/2,k-(n+1)/2,1+n%2);
    }
    if(k<=n/2)return 2*k;
    return 2*person((n+1)/2,k-n/2,2-n%2)-1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<person(n,k,2)<<"\n";
    }
}