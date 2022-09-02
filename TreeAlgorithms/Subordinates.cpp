#include<bits/stdc++.h>

using namespace std;

#define ll long long

int dfs(vector<int> v[], int k, int child[]){
    child[k]=0;
    for(int i=0; i<v[k].size(); i++){
        child[k]+=dfs(v,v[k][i],child);
    }
    return child[k]+1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v[n+1];
    for(int i=2; i<n+1; i++){
        int a;
        cin>>a;
        v[a].push_back(i);
    }
    int child[n+1];
    dfs(v,1,child);
    for(int i=1; i<n+1; i++){
        cout<<child[i]<<" ";
    }
    cout<<"\n";
}