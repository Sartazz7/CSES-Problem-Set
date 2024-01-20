#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> v;

void print(map<char,int> m, string s, int n){
    if(s.size()==n){
        v.push_back(s);
        return;
    }
    for(auto x: m){
        if(x.second==0)continue;
        m[x.first]--;
        print(m,s+x.first,n);
        m[x.first]++;
    }
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    map<char,int> m;
    for(int i=0; i<n; i++){
        m[s[i]]++;
    }
    print(m,"",n);
    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
}