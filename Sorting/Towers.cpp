#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int,int> m;
    for(int i=0; i<n; i++){
        auto it=m.upper_bound(a[i]);
        if(it!=m.end()){
            it->second--;
            if(it->second==0)m.erase(it);
        }
        m[a[i]]++;
    }
    int ans=0;
    for(auto x: m){
        ans+=x.second;
    }
    cout<<ans<<"\n";
}