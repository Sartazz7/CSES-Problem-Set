#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        auto it=lower_bound(ans.begin(),ans.end(),a[i]);
        if(it==ans.end())ans.push_back(a[i]);
        else *it=a[i];
    }
    cout<<ans.size()<<"\n";
    return 0;
}