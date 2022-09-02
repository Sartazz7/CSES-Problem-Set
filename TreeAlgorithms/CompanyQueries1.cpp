#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct node{
    int val;
    node *next;
    node(int v){
        val=v;
        next=NULL;
    }
};

vector<int> *pos;

vector<int> List(node *leaf, int idx){
    node *temp=leaf;
    vector<int> ans;
    while(temp!=NULL){
        if(pos[temp->val][0]==-1){
            pos[temp->val]={idx,(int)ans.size()};
        }
        ans.push_back(temp->val);
        temp=temp->next;
    }
    return ans;
}

int main(){
    int n,q;
    cin>>n>>q;
    node *a[n+1];
    pos=new vector<int> [n+1];
    bool l[n+1];
    for(int i=0; i<n+1; i++){
        a[i]=new node(i);
        pos[i]={-1,-1};
        l[i]=true;
    }
    for(int i=2; i<n+1; i++){
        int p;
        cin>>p;
        a[i]->next=a[p];
        l[p]=false;
    }
    vector<vector<int>> v;
    for(int i=1; i<n+1; i++){
        if(l[i])v.push_back(List(a[i],(int)v.size()));
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        int a=pos[x][0], b=pos[x][1];
        if(v[a].size()<=b+k)cout<<-1<<'\n';
        else cout<<v[a][b+k]<<"\n";
    }
    return 0;
}