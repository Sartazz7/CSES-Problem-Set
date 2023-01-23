#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    if(n==3 || n==2){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    if(n==4){
        cout<<"2 4 1 3\n";
        return 0;
    }
    int a[n];
    for(int i=0; 2*i+1<=n; i++){
        a[i]=2*i+1;
    }
    for(int i=0; 2*i+2<=n; i++){
        a[(n-1)/2+i+1]=2*i+2;
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}