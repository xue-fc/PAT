/*
    由中序前序得到整个树，这一过程我还不太熟悉，之后再练练
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;
int N,tmp;
vector<int> preOrder;
vector<int> midOrder;
vector<int> postOrder;
bool flag;
bool isBST(int left,int right){
    if(right-left<=1)
        return true;
    flag=false;
    int root = preOrder[left];
    int mid=-1;
    for(int i=left+1;i<right;i++){
        if(preOrder[i]<root && flag)
            return false;
        if(!flag && preOrder[i]>root){
            mid = i;
        }
        flag = preOrder[i]>root;

    }
    if(mid==-1) return true;
    return isBST(left+1,mid) && isBST(mid,right);
}

bool isMBST(int left,int right){
    if(right-left<=1)
        return true;
    flag=false;
    int root = preOrder[left];
    int mid=-1;
    for(int i=left+1;i<right;i++){
        if(preOrder[i]>root && flag)
            return false;
        if(!flag && preOrder[i]<root){
            mid = i;
        }
        flag = preOrder[i]<root;
    }
    if(mid==-1) return true;
    return isMBST(left+1,mid) && isMBST(mid,right);
}

void getPost(int root, int tail){
    if(root>tail) return;
    int i=root+1,j=tail;
    if(flag){
        while(i<=tail && preOrder[root] > preOrder[i]) i++;//while里必须加等号，要让i加超了，这样可以在下一个里直接return
        while(j>=root && preOrder[root] <= preOrder[j]) j--;
    }
    else{
        while(i<=tail && preOrder[root] <= preOrder[i]) i++;
        while(j>root && preOrder[root] > preOrder[j]) j--;
    }
    getPost(root+1,j);
    getPost(i,tail);
    postOrder.push_back(preOrder[root]);
}

int main(){
    cin>>N;
    preOrder.resize(N);
    for(int i=0;i<N;i++){
        cin>>tmp;
        preOrder[i] = tmp;
    }
    midOrder = vector<int>(preOrder);
    sort(midOrder.begin(),midOrder.end());
    bool B=isBST(0,N);
    bool M=isMBST(0,N);
    if(B)
    {
        cout<<"YES\n";
        midOrder = preOrder;
        sort(midOrder.begin(),midOrder.end());
        flag = true;
        getPost(0,N-1);
        for(auto it=postOrder.begin();it!=postOrder.end();it++){
            if(it==postOrder.begin())
                cout<<*it;
            else{
                cout<<" "<<*it;
            }
        }
    }
    else if(M){
        cout<<"YES\n";
        midOrder = preOrder;
        sort(midOrder.begin(),midOrder.end());
        flag = false;
        getPost(0,N-1);
        for(auto it=postOrder.begin();it!=postOrder.end();it++){
            if(it==postOrder.begin())
                cout<<*it;
            else{
                cout<<" "<<*it;
            }
        }
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
    return 0;
}
