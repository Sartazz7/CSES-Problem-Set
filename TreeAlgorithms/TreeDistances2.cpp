#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n;
vector<ll> *v;
vector<vector<ll>> *w;

vector<ll> sum(int k, int e){
    ll s=0, nd=1;
    for(int i=0; i<w[k].size(); i++){
        if(w[k][i][2]==e)continue;
        s+=w[k][i][0]+w[k][i][1];
        nd+=w[k][i][1];
    }
    return {s,nd};
}

vector<ll> dfsUp(int k, int p){
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            w[k].push_back(dfsUp(v[k][i],k));
        }
    }
    vector<ll> s=sum(k,-1);
    return {s[0],s[1],k};
}

void dfsDown(int k, int p, vector<ll> s){
    w[k].push_back(s);
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i]!=p){
            vector<ll> t=sum(k,v[k][i]);
            dfsDown(v[k][i],k,{t[0],t[1],k});
        }
    }
}

int main(){
    cin>>n;
    v=new vector<ll> [n+1];
    w=new vector<vector<ll>> [n+1];
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsUp(1,-1);
    dfsDown(1,-1,{0,0,-1});
    for(int i=1; i<n+1; i++){
        cout<<sum(i,-1)[0]<<" ";
    }
    cout<<"\n";
    return 0;
}