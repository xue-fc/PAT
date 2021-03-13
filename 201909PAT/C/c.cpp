#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

struct node{
    string data;
    int left=-1;
    int right=-1;

    node(){};
    node(string &d,int a,int b){
        data = d;
        left = a;
        right = b;
    }
};
vector<node> tree;
string helper(int root){
    if(tree[root].left == -1 && tree[root].right == -1){
        return "("+tree[root].data+")";
    }
    if(tree[root].left != -1 && tree[root].right != -1){
        return "(" + helper(tree[root].left) + helper(tree[root].right) + tree[root].data+ ")";
    }
    if(tree[root].left != -1)
        return "("+tree[root].data + helper(tree[root].left)+")";
    else
        return "("+tree[root].data + helper(tree[root].right)+")";
}
int main(){
    int N,a,b;
    cin>>N;
    tree.resize(N+1);
    string d;
    vector<bool> isRoot(N+1,true);
    isRoot[0] = false;
    for(int i=1;i<=N;i++){
        cin>>d>>a>>b;
        if(a!=-1)
            isRoot[a]=false;
        if(b!=-1)
            isRoot[b]=false;
        tree[i] = node(d,a,b);
    }
    int root = find(isRoot.begin(),isRoot.end(),true) - isRoot.begin();
    cout<<helper(root)<<endl;
    return 0;
}