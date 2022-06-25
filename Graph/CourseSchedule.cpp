#include<bits/stdc++.h>

using namespace std;

#define ll long long   

int n,m;
vector<int> *v;
int *a,*d;
int t;

bool dfs(int k){
    a[k]=1;
    for(int i=0; i<v[k].size(); i++){
        if(a[v[k][i]]==-1){
            if(!dfs(v[k][i]))return false;
        }
        else {
            if(d[v[k][i]]==-1)return false;
        }
    }
    d[k]=t;
    t++;
    return true;
}

int main(){
    cin>>n>>m;
    v = new vector<int> [n+1];
    a = new int [n+1];
    d = new int [n+1];
    t=0;
    for(int i=0; i<m; i++){
        int c,b;
        cin>>c>>b;
        v[c].push_back(b);
    }
    for(int i=0; i<n+1; i++){
        a[i]=-1;
        d[i]=-1;
    }
    for(int i=1; i<n+1; i++){
        if(a[i]==-1){
            if(!dfs(i)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    vector<vector<int>> v1;
    for(int i=1; i<n+1; i++){
        v1.push_back({d[i],i});
    }
    sort(v1.begin(),v1.end());
    for(int i=0; i<n; i++){
        cout<<v1[n-i-1][1]<<" ";
    }
    cout<<"\n";
    return 0;
}