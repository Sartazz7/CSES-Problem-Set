#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1001

string s[N];
string *dp[N];
int n,m;

string path(int x, int y){
    //cout<<x<<" "<<y<<"\n";
    if(x<0 || x>=n || y<0 || y>=m)return "N";
    if(dp[x][y]!="M")return dp[x][y];
    dp[x][y]="N";
    if(s[x][y]=='#')dp[x][y]="N";
    else if(s[x][y]=='B')dp[x][y]="";
    else {
        vector<pair<int,string> > v;
        if(path(x+1,y)!="N")v.push_back({path(x+1,y).size()+1,path(x+1,y)+'D'});
        if(path(x,y+1)!="N")v.push_back({path(x,y+1).size()+1,path(x,y+1)+'R'});
        if(path(x-1,y)!="N")v.push_back({path(x-1,y).size()+1,path(x-1,y)+'U'});
        if(path(x,y-1)!="N")v.push_back({path(x,y-1).size()+1,path(x,y-1)+'L'});
        if(v.size()!=0){
            sort(v.begin(),v.end());
            dp[x][y]=v[0].second;
        }
    }
    return dp[x][y];
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int x,y;
    for(int i=0; i<n; i++){
        dp[i] = new string [m];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A'){
                x=i;
                y=j;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j]="M";
        }
    }
    if(path(x,y)=="N")cout<<"NO\n";
    else {
        cout<<"YES\n";
        cout<<dp[x][y].size()<<"\n";
        reverse(dp[x][y].begin(),dp[x][y].end());
        cout<<dp[x][y]<<"\n";
    }
    return 0;
}