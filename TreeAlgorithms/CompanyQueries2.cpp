#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n,q;
vector<int> *adj;
vector<vector<int>> v;
vector<int> *pos;

void create(vector<int> &v1, int k){
    v1.push_back(k);
    pos[k]={(int)v.size(),(int)v1.size()-1};
    if(adj[k].size()==0){
        v.push_back(v1);
    }
    for(int i=0; i<adj[k].size(); i++){
        create(v1,adj[k][i]);
    }
    v1.pop_back();
}

bool bs1(vector<int> &v1, int l, int r, int k){
    if(l==r){
        if(v1[l]==k)return true;
        return false;
    }
    int m=(l+r)/2;
    if(v1[m]>=k)return bs1(v1,l,m,k);
    return bs1(v1,m+1,r,k);
}

int bs2(vector<int> &v1, vector<int> &v2, int p1, int l, int r){
    if(l==r)return v2[l];
    int m=(l+r+1)/2;
    if(bs1(v1,0,p1,v2[m]))return bs2(v1,v2,p1,m,r);
    return bs2(v1,v2,p1,l,m-1);
}

int main(){
    cin>>n>>q;
    adj=new vector<int> [n+1];
    pos=new vector<int> [n+1];
    for(int i=2; i<n+1; i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    vector<int> v1;
    create(v1,1);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<bs2(v[pos[a][0]],v[pos[b][0]],pos[a][1],0,pos[b][1])<<"\n";
    }
}