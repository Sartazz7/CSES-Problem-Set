#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    vector<vector<int> > v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back({a,i+1});
    }
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    while(i<j){
        if(v[i][0]+v[j][0]==x){
            cout<<v[i][1]<<" "<<v[j][1]<<"\n";
            return 0;
        }
        if(v[i][0]+v[j][0]>x)j--;
        else i++;
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}