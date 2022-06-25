#include<bits/stdc++.h>

using namespace std;

#define ll long long   

int n,m;
vector<int> *v;
int *p,*a,*d;

int dfs(int k){
    a[k]=1;
    for(int i=0; i<v[k].size(); i++){
        if(a[v[k][i]]==-1){
            p[v[k][i]]=k;
            int x=dfs(v[k][i]);
            if(x!=-1)return x;
        }
        else {
            if(d[v[k][i]]==-1){
                p[v[k][i]]=k;
                return k;
            }
        }
    }
    d[k]=1;
    return -1;
}

vector<int> createCycle(int u){
    vector<int> v1;
    int k=u;
    while(k!=p[u]){
        v1.push_back(u);
        u=p[u];
    }
    v1.push_back(u);
    v1.push_back(p[u]);
    return v1;
}

int main(){
    cin>>n>>m;
    v = new vector<int> [n+1];
    p = new int [n+1];
    a = new int [n+1];
    d = new int [n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0; i<n+1; i++){
        p[i]=-1;
        a[i]=-1;
        d[i]=-1;
    }
    for(int i=1; i<n+1; i++){
        if(a[i]==-1){
            int x=dfs(i);
            if(x!=-1){
                vector<int> v1=createCycle(x);
                cout<<v1.size()<<"\n";
                for(int i=v1.size()-1; i>=0; i--){
                    cout<<v1[i]<<" ";
                }
                cout<<"\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}