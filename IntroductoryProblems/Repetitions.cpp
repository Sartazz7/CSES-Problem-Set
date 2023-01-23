#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int c=1;
    int ans=1;
    for(int i=1; i<s.size(); i++){
        if(s[i]==s[i-1])c++;
        else{
            ans=max(ans,c);
            c=1;
        }
    }
    ans=max(ans,c);
    cout<<ans<<"\n";
}