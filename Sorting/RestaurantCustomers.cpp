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
        v.push_back({a,b});
    }
    priority_queue<int,vector<int>,greater<int> > q;
    sort(v.begin(),v.end());
    int k=0;
    int ans=0;
    for(int i=0; i<n; i++){
        k++;
        q.push(v[i][1]);
        while(!q.empty() && q.top()<=v[i][0]){
            q.pop();
            k--;
        }
        ans=max(ans,k);
    }
    cout<<ans<<"\n";
    return 0;
}