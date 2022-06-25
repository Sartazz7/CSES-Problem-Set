#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    vector<vector<int> > v;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int k=v[0][0];
    int ans=1;
    for(int i=1; i<n; i++){
        if(v[i][1]>=k){
            k=v[i][0];
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}