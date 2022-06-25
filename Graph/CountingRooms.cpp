#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1001

string s[N];
bool vis[N][N];
int n,m;

void visit(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || s[i][j]=='#' || vis[i][j])return;
    vis[i][j]=true;
    visit(i+1,j);
    visit(i-1,j);
    visit(i,j+1);
    visit(i,j-1);
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int r=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j]=false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]=='.' && !vis[i][j]){
                r++;
                visit(i,j);
            }
        }
    }
    cout<<r<<"\n";
    return 0;
}