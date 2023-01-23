#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int,int> m;
    m[0]=x;
    priority_queue<vector<int>> q;
    q.push({x,0});
    for(int i=0; i<n; i++){
        auto it=m.lower_bound(a[i]);
        it--;
        q.push({a[i]-it->first,it->first});
        q.push({it->second-a[i],a[i]});
        m[a[i]]=it->second;
        it->second=a[i];
        while(q.top()[0] > m[q.top()[1]]-q.top()[1])q.pop();
        cout<<q.top()[0]<<" ";
    }
    cout<<'\n';
}