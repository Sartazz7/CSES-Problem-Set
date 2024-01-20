#include<bits/stdc++.h>

using namespace std;

#define ll long long

string solve(string s){
    int a[26];
    int n=s.size();
    for(int i=0; i<26; i++){
        a[i]=0;
    }
    for(int i=0; i<n; i++){
        a[s[i]-'A']++;
    }
    int odd=0;
    for(int i=0; i<26; i++){
        if(a[i]%2==1)odd++;
    }
    if((n%2==0 && odd>0) || odd>1)return "NO SOLUTION";
    int k=0;
    for(int i=0; i<26; i++){
        if(a[i]%2==1){
            s[n/2]='A'+i;
            a[i]--;
        }
        for(int j=0; j<a[i]/2; j++){
            s[k]='A'+i;
            s[n-k-1]='A'+i;
            k++;
        }
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<"\n";
}