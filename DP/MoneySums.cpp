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
    set<int> s;
    for(int i=0; i<n; i++){
        set<int> t;
        for(auto x:s){
            t.insert(x+a[i]);
        }
        for(auto x:t){
            s.insert(x);
        }
        s.insert(a[i]);
    }
    cout<<s.size()<<"\n";
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<"\n";
}