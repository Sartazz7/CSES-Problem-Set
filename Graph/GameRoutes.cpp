#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n,m;
vector<int> *v;
int mod=1000000007;
ll *ways;

ll dfs(int k){
    if(ways[k]!=-1)return ways[k];
    ways[k]=0;
    for(int i=0; i<v[k].size(); i++){
        ways[k]=(ways[k]+dfs(v[k][i]))%mod;
    }
    return ways[k];
}

int main(){
    cin>>n>>m;
    v = new vector<int> [n+1];
    ways = new ll [n+1];
    for(int i=0; i<n+1; i++){
        ways[i]=-1;
    }
    ways[n]=1;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    cout<<dfs(1)<<"\n";
}