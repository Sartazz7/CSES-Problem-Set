#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0,j=n-1,ans=0;
    while(i<j){
        if(a[i]+a[j]<=x){
            ans++;
            i++;
            j--;
        }
        else {
            j--;
            ans++;
        }
    }
    if(i==j)ans++;
    cout<<ans<<"\n";
    return 0;
}