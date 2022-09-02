#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> dfs(vector<int> v[], int k, int p){
    int taken=0;
    int edges=0;
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            vector<int> v1=dfs(v,v[k][i],k);
            if(v1[0]==0)taken=1;
            edges+=v1[1];
        }
    }
    return {taken,edges+taken};
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