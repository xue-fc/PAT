#include<iostream>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> post,in;

struct node{
    int v=-1;
    int depth=0;
    node *father=NULL;
    node* left=NULL;
    node* right=NULL;

    node(){};
};

bool isThis(node &t,int v){
    if(t.v == v)
        return true;
    return false;
}

vector<node> allNodes; 
int depth=0;
node* helper(vector<int> &post=post,vector<int> &in=in){
    if(post.size()==0)
        return NULL;
    int root = *(post.end()-1);
    auto root_pos = find(in.begin(),in.end(),root);
    auto it=post.begin();
    
    vector<int> left_in = vector<int>(in.begin(),root_pos);
    vector<int> right_in = vector<int>(root_pos+1,in.end());
    for(;it!=post.end();it++){
        if(find(left_in.begin(),left_in.end(),*it)==left_in.end())
            break;       
    }
    vector<int> left_post = vector<int>(post.begin(),it);
    vector<int> right_post = vector<int>(it,post.end()-1);
    node *tmp = new node;
    tmp->v = root;
    tmp->depth = depth;
    depth++;
    tmp->left = helper(left_post,left_in);
    if(tmp->left != NULL)
    {
        tmp->left->father = tmp;
        allNodes.push_back(*(tmp->left));
    }
    tmp->right = helper(right_post,right_in);
    if(tmp->right != NULL) 
    {
        tmp->right->father = tmp;
        allNodes.push_back(*(tmp->right));
    }
    depth--;
    return tmp;
}

int main(){
    int N;
    cin>>N;
    post.resize(N);
    in.resize(N);
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        post[i] = tmp;
    }
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        in[i] = tmp;
    }
    node* root = helper();
    allNodes.push_back(*root);
    int M;
    cin>>M;
    getchar();
    node a,b;
    int cur,cur2;
    for(int i=0;i<M;i++){
        string s;
        getline(cin,s);
        char rear = *(s.end()-1);
        if(rear>='a' && rear<='z'){
            switch (rear)
            {
            case 't':
            {   
                int t=0;
                while(s[t]!=' ') t++;
                cur = stoi(s.substr(0,t));
                if(root->v != cur){
                    cout<<"No\n";
                }
                else{
                    cout<<"Yes\n";
                }
                break;
            }
            case 's':
            {
                int t=0;
                while(s[t]!=' ') t++;
                cur = stoi(s.substr(0,t));
                s.erase(s.begin(),s.begin()+t+5);
                t=0;
                while(s[t]>='0' && s[t]<='9') t++;
                cur2 = stoi(s.substr(0,t));
                if(cur==cur2)
                {
                    cout<<"No\n";
                    break;
                }
                for(auto it=allNodes.begin();it!=allNodes.end();it++){
                    if(it->v==cur)
                        a = *it;
                    if(it->v==cur2)
                        b = *it;
                }
                         
                if(a.father!=NULL && b.father!=NULL && a.father->v == b.father->v)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            case 'l':
            {
                int t=0;
                while(s[t]!=' ') t++;
                cur = stoi(s.substr(0,t));
                s.erase(s.begin(),s.begin()+t+5);
                t=0;
                while(s[t]!=' ') t++;
                cur2 = stoi(s.substr(0,t));
                if(cur==cur2)
                {
                    cout<<"No\n";
                    break;
                }
                for(auto it=allNodes.begin();it!=allNodes.end();it++){
                    if(it->v==cur)
                        a = *it;
                    if(it->v==cur2)
                        b = *it;
                }     
                if(a.v==b.v)
                {
                    cout<<"No\n";
                    break; 
                }  
                if(a.depth == b.depth)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            case 'e':
            {
                bool flag = true;
                for(auto it=allNodes.begin();it!=allNodes.end();it++){
                    if((it->left==NULL && it->right!=NULL) ||(it->left!=NULL && it->right==NULL)){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            }
        }
        else{
            int t=0;
            while(s[t]!=' ') t++;
            cur = stoi(s.substr(0,t));
            t = s.size()-1;
            while(s[t]!=' ') t--;
            int cur2 = stoi(s.substr(t,s.size()-1));
            if(cur==cur2)
            {
                cout<<"No\n";
                continue;
            }
            for(auto it=allNodes.begin();it!=allNodes.end();it++){
                if(it->v==cur)
                    a = *it;
                if(it->v==cur2)
                    b = *it;
            }  
            if(a.v==b.v)
            {
                cout<<"No\n";
                continue; 
            }  
            while(cur!=0)
            {
                cur=cur/10;
                s.erase(s.begin());
            }
            switch (s[8])
            {
            case 'p':
            {   
                if(b.father!=NULL && b.father->v==a.v)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            case 'l':
            {   
                if(b.left!=NULL && b.left->v==a.v)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            case 'r':
            {   
                if(b.right!=NULL && b.right->v==a.v)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            }
            }
        }
    }
    return 0;
}