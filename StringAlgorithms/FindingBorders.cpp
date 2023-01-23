#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int p[n];
    p[0]=0;
    for(int i=1; i<n; i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j])j=p[j-1];
        if(s[i]==s[j])j++;
        p[i]=j;
    }
    int i=p[n-1];
    vector<int> ans;
    while(i>0){
        ans.push_back(i);
        i=p[i-1];
    }
    sort(ans.begin(),ans.end());
    for(auto e:ans){
        cout<<e<<" ";
    }
    return 0;
}