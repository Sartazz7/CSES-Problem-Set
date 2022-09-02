#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> dfs(vector<int> v[], int k, int p){
    int a=0;
    vector<int> b;
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            vector<int> v1=dfs(v,v[k][i],k);
            b.push_back(v1[0]+1);
            a=max(a,v1[1]);
        }
    }
    if(b.size()==0)return {0,0};
    if(b.size()==1)return {b[0],max(a,b[0])};
    sort(b.begin(),b.end(),greater<int>());
    return {b[0],max(a,b[0]+b[1])};
}

int main(){
    int n;
    cin>>n;
    vector<int> v[n+1];
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<dfs(v,1,0)[1]<<"\n";
}