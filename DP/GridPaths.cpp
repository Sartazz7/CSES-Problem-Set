#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1001

int mod=1000000007;
int n;
string *s;
ll *dp[N];

ll ans(int i, int j){
    if(i>=n || j>=n)return 0;
    if(s[i][j]=='*')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=(ans(i+1,j)+ans(i,j+1))%mod;
    return dp[i][j];
}

int main(){
    cin>>n;
    s = new string [n];
    for(int i=0; i<n; i++){
        dp[i]=new ll [n];
        for(int j=0; j<n; j++){
            dp[i][j]=-1;
        }
        cin>>s[i];
    }
    dp[n-1][n-1]=1;
    cout<<ans(0,0)<<"\n";
    return 0;
}