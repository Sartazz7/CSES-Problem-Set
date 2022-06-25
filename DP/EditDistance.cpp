#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(), m=s2.size();
    int a[n+1][m+1];
    for(int i=0; i<n+1; i++){
        a[i][0]=i;
    }
    for(int i=0; i<m+1; i++){
        a[0][i]=i;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s1[i-1]==s2[j-1])a[i][j]=a[i-1][j-1];
            else a[i][j]=a[i-1][j-1]+1;
            a[i][j]=min(a[i][j],1+a[i-1][j]);
            a[i][j]=min(a[i][j],1+a[i][j-1]);
        }
    }
    cout<<a[n][m]<<"\n";
    return 0;
}