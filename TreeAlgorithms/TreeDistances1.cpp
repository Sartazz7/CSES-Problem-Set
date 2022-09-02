#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n;
vector<int> *v;
vector<vector<int>> *w;

int dfsUp(int k, int p){
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            w[k].push_back({dfsUp(v[k][i],k),v[k][i]});
        }
    }
    sort(w[k].begin(),w[k].end(),greater<vector<int>>());
    return w[k][0][0]+1;
}

void dfsDown(int k, int p, int d){
    w[k].push_back({d,p});
    sort(w[k].begin(),w[k].end(),greater<vector<int>>());
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            if(v[k][i]==w[k][0][1]){
                dfsDown(v[k][i],k,w[k][1][0]+1);
            }
            else {
                dfsDown(v[k][i],k,w[k][0][0]+1);
            }
        }
    }
}

int main(){
    cin>>n;
    v=new vector<int> [n+1];
    w=new vector<vector<int>> [n+1];
    for(int i=0; i<n+1; i++){
        w[i].push_back({0,-1});
    }
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsUp(1,-1);
    dfsDown(1,-1,0);
    for(int i=1; i<n+1; i++){
        cout<<w[i][0][0]<<" ";
    }
    cout<<"\n";
    return 0;
}