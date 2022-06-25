#include<bits/stdc++.h>

using namespace std;

#define ll long long

set<int> dig(int n){
    set<int> s;
    while(n>0){
        if(n%10>0)s.insert(n%10);
        n/=10;
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1; i<n+1; i++){
        a[i]=INT_MAX;
    }
    for(int i=1; i<n+1; i++){
        set<int> s=dig(i);
        for(auto x:s){
            a[i]=min(a[i],a[i-x]);
        }
        a[i]+=1;
    }
    cout<<a[n]<<"\n";
    return 0;
}