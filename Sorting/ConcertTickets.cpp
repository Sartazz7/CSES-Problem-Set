#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }
    for(int i=0; i<m; i++){
        auto it=mp.upper_bound(b[i]);
        if(it==mp.begin())cout<<-1<<'\n';
        else {
            it--;
            cout<<it->first<<"\n";
            it->second = it->second-1;
            if(it->second==0)mp.erase(it);
        }
    }
}