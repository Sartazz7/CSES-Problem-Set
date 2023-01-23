#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<vector<int>> b;
    for(int i=0; i<n; i++){
        b.push_back({a[i],i});
    }
    sort(b.begin(), b.end());
    int ans=1;
    for(int i=1; i<n; i++){
        if(b[i][1] < b[i-1][1])ans++;
    }
    cout<<ans<<'\n';
}