#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    int p[m];
    p[0]=0;
    for(int i=1; i<m; i++){
        int j=p[i-1];
        while(j>0 && t[i]!=t[j]){
            j=p[j-1];
        }
        if(t[i]==t[j])j++;
        p[i]=j;
    }
    int ans=0;
    int i=0, j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else {
            if(j==0)i++;
            else j=p[j-1];
        }
        if(j==m){
            ans++;
            j=p[j-1];
        }
    }
    cout<<ans<<"\n";
}