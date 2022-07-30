#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll *dp;
int n;
vector<vector<ll>> v;

int lb(int l, int r, ll k){
    if(l==r){
        if(v[l][0]>k)return l;
        return -1;
    }
    int m=(l+r)/2;
    if(k<v[m][0])return lb(l,m,k);
    return lb(m+1,r,k);
}

ll maxVal(int i){
    if(i==-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int j=lb(0,n-1,v[i][1]);
    dp[i]=max(maxVal(i+1),maxVal(j)+v[i][2]);
    return dp[i];
}

int main(){
    cin>>n;
    dp = new ll [n];
    for(int i=0; i<n; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
        dp[i]=-1;
    }
    sort(v.begin(),v.end());
    dp[n-1]=v[n-1][2];
    cout<<maxVal(0)<<"\n";
    return 0;
}