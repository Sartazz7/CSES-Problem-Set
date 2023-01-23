
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1000005

int f[N];
int p[N];

void divisors(vector<vector<int>> &v, int i, int x){
    if(i==v.size()){
        f[x]++;
        return;
    }
    int y=1;
    for(int j=0; j<=v[i][1]; j++){
        divisors(v,i+1,x*y);
        y*=v[i][0];
    }
}

int ans(int n, int a[]){
    for(int i=0; i<N; i++){
        f[i]=0;
        p[i]=i;
    }
    for(int i=2; i*i<=N; i++){
        for(int j=i*i; j<N; j+=i){
            if(p[j]==j)p[j]=i;
        }
    }
    for(int i=0; i<n; i++){
        map<int,int> m;
        while(a[i]>1){
            m[p[a[i]]]++;
            a[i]/=p[a[i]];
        }
        vector<vector<int>> v;
        for(auto x:m){
            v.push_back({x.first,x.second});
        }
        divisors(v,0,1);
    }
    for(int i=N-1; i>=1; i--){
        if(f[i]>=2)return i;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<ans(n,a)<<"\n";
}