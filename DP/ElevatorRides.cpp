#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> *dp;
int n,x;
ll *a;

int main(){
    cin>>n>>x;
    a = new ll [n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

}