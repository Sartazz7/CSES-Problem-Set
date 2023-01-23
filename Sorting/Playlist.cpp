#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int,bool> m;
    for(int i=0; i<n; i++){
        m[a[i]]=false;
    }
    int ans=0;
    int j=0;
    for(int i=0; i<n; i++){
        if(m[a[i]]){
            while(m[a[i]]){
                m[a[j]]=false;
                j++;
            }
        }
        m[a[i]]=true;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
}