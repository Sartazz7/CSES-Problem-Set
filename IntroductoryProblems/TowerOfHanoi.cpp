#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> v;

void opr(int p1, int p2, int p3, int n){
    if(n==0)return;
    opr(p1,p3,p2,n-1);
    v.push_back({p1,p3});
    opr(p2,p1,p3,n-1);
}

int main(){
    int n;
    cin>>n;
    opr(1,2,3,n);
    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i][0]<<" "<<v[i][1]<<"\n";
    }
}