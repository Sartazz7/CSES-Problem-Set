#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct Node {
    int idx,l,r;
    vector<Node*> next;
    Node(int idx1, int l1, int r1){
        idx=idx1;
        l=l1;
        r=r1;
    }
};

class Trie{
    Node *root;
    vector<string> v;
    Node *leaf;
    ll mod=1000000007;

    int match(string &s, int l, Node *node){
        int len=0;
        for(len=1; len<=s.size()-l; len++){
            if(node->l+len-1>node->r)return len-1;
            if(s[l+len-1]!=v[node->idx][node->l+len-1])return len-1;
        }
        return len-1;
    }

    void recInsert(string &s, int l, Node *node){
        for(int edge=0; edge<node->next.size(); edge++){
            Node *child=node->next[edge];
            int len=match(s,l,child);
            if(len==0)continue;
            if(len==child->r-child->l+1){
                recInsert(s,l+len,child);
                return;
            }
            Node *mid=new Node(child->idx,child->l,child->l+len-1);
            child->l=child->l+len;
            mid->next.push_back(child);
            node->next[edge]=mid;
            if(len==s.size()-l){
                mid->next.push_back(leaf);
            }
            else{
                Node *child1=new Node(v.size()-1,l+len,s.size()-1);
                child1->next.push_back(leaf);
                mid->next.push_back(child1);
            }
            return;
        }
        Node *child1=new Node(v.size()-1,l,s.size()-1);
        child1->next.push_back(leaf);
        node->next.push_back(child1);
    }

    ll recNumWays(string &s, int l, Node *node){
        if(l==s.size())return 1;
        ll ans=0;
        for(int edge=0; edge<node->next.size(); edge++){
            Node *child=node->next[edge];
            if(child->idx==0)ans=(ans+recNumWays(s,l,root))%mod;
            int len=match(s,l,child);
            if(len<child->r-child->l+1)continue;
            // cout<<s.substr(l,s.size()-l)<<" "<<len<<"\n";
            ans=(ans+recNumWays(s,l+len,child))%mod;
        }
        // cout<<s.substr(l,s.size()-l)<<" "<<ans<<"\n";
        return ans;
    }

    void printChild(Node *node){
        cout<<v[node->idx].substr(node->l,node->r-node->l+1)<<" -> ";
        for(auto child: node->next){
            cout<<v[child->idx].substr(child->l,child->r-child->l+1)<<" ";
        }
        cout<<"\n";
        for(auto child: node->next){
            printChild(child);
        }
    }

    public:
    Trie(){
        v.push_back("$");
        root=new Node(0,0,0);
        leaf=new Node(0,0,0);
    }

    void printTree(){
        printChild(root);
    }

    void insert(string s){
        v.push_back(s);
        recInsert(s,0,root);
    }

    ll numWays(string s){
        return recNumWays(s,0,root);
    }
};

int main(){
    Trie t=Trie();
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string p;
        cin>>p;
        t.insert(p);
    }
    t.printTree();
    cout<<"123\n";
    cout<<t.numWays(s)<<"\n";
}