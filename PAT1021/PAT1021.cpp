#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
void helper(vector<int> po, vector<int> io,int root);
vector<int> tree = vector<int>(1000,-1);
int main(){
    int N;
    vector<int> po,io;
    cin>>N;

    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        po.push_back(tmp);
    }

   for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        io.push_back(tmp);
    }

    helper(po,io,0);
    int i = 0;
    while(N>0){
        if(tree[i]!=-1)
        {
            cout<<tree[i]<<((N==1) ? "" : " ");
            N--;
        }
        i++;
    }
    return 0;
}

void helper(vector<int> po, vector<int> io,int root){
    if(po.empty() || io.empty() || root >= tree.size()){
        return;
    }
    vector<int>::iterator it = po.end();
    vector<int>::iterator it2 = po.begin();
    it--;
    tree[root] = *it;
    vector<int>::iterator split = find(io.begin(),io.end(),*it);//分割io为两个子树，split是根
    for(;it2!=po.end();it2++){
        it = find(io.begin(),split,*it2);
        if(it == split)
            break;
    }//it2是分割po的位置，是右子树第一个
    vector<int> tpo_l = vector<int>(po.begin(),it2);
    vector<int> tpo_r = vector<int>(it2,po.end()-1);
    vector<int> tio_l = vector<int>(io.begin(),split);
    split++;
    vector<int> tio_r = vector<int>(split,io.end());
    helper(tpo_l,tio_l,root*2 + 1);
    helper(tpo_r,tio_r,root*2 + 2);
}

