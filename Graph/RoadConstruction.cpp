#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct node{
    node *next;
    int size;
    node(){
        next=NULL;
        size=1;
    }
};

vector<int> join(node *a, node *b){
    node *temp1=a;
    int l1=0;
    while(temp1->next!=NULL){
        temp1=temp1->next;
        // cout<<temp1->size<<"\n";
        l1++;
    }
    node *temp2=b;
    int l2=0;
    while(temp2->next!=NULL){
        temp2=temp2->next;
        l2++;
    }
    if(temp1==temp2){
        return {0,temp1->size};
    }
    if(l1>l2){
        temp2->next=temp1;
        temp1->size+=temp2->size;
        return {1,temp1->size};
    }
    else {
        temp1->next=temp2;
        temp2->size+=temp1->size;
        return {1,temp2->size};
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    node* a[n+1];
    for(int i=0; i<n+1; i++){
        a[i]=new node();
    }
    // cout<<1<<"\n";
    priority_queue<int> q;
    int k=n;
    for(int i=0; i<m; i++){
        int b,c;
        cin>>b>>c;
        vector<int> v=join(a[b],a[c]);
        k-=v[0];
        q.push(v[1]);
        cout<<k<<" "<<q.top()<<"\n";
    }
}