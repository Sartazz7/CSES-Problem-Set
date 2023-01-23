#include<bits/stdc++.h>

using namespace std;

void ans1(int i, int j, int b[], int &ans){
    if(j<i)swap(i,j);
    if(j-i==1){
        if(b[j]<b[i])ans--;
    }
    else{
        if(b[j]<b[j-1])ans--;
        if(b[i+1]<b[i])ans--;
    }
    if(b[j+1]<b[j])ans--;
    if(b[i]<b[i-1])ans--;
    swap(b[i],b[j]);
    if(j-i==1){
        if(b[j]<b[i])ans++;
    }
    else{
        if(b[j]<b[j-1])ans++;
        if(b[i+1]<b[i])ans++;
    }
    if(b[j+1]<b[j])ans++;
    if(b[i]<b[i-1])ans++;
}

int main(){
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1; i<n+1; i++){
        cin>>a[i];
    }
    int b[n+2];
    for(int i=1; i<n+1; i++){
        b[a[i]]=i;
    }
    b[0]=0;
    b[n+1]=n+1;
    int ans=1;
    for(int i=2; i<n+1; i++){
        if(b[i] < b[i-1])ans++;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans1(a[x],a[y],b,ans);
        swap(a[x],a[y]);
        cout<<ans<<'\n';
    }
}