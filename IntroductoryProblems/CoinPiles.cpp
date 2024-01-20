#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a<b)swap(a,b);
        if(a<=2*b && (2*b-a)%3==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
}