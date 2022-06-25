#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v[n+1];
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }

}