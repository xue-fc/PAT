#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> helper(vector<int> in,vector<int> pre){
    if(in.size()!=pre.size()){
        cout<<"ERROR!"<<endl;
    }
    vector<int> res;
    if(in.size()==0){
        return res;
    }
    int root = pre[0];
    auto rootPos = find(in.begin(),in.end(),root);
    vector<int> leftIn = vector<int>(in.begin(),rootPos);
    vector<int> rightIn = vector<int>(rootPos+1,in.end());
    auto it=pre.begin()+1;
    for(it;it!=pre.end();it++){
        auto r = find(leftIn.begin(),leftIn.end(),*it);
        if(r==leftIn.end())
            break;
    }
    vector<int> leftPre = vector<int>(pre.begin()+1,it);
    vector<int> rightPre = vector<int>(it,pre.end());

    vector<int> leftRes = helper(leftIn,leftPre);
    vector<int> rightRes = helper(rightIn,rightPre);
    if(leftRes.size()>=rightRes.size()){
        leftRes.insert(leftRes.begin(),root);
        return leftRes;
    }else{
        for(int i=0;i<leftRes.size();i++){
            rightRes[i] = leftRes[i];
        }
        rightRes.insert(rightRes.begin(),root);
        return rightRes;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> inOrder,preOrder;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        inOrder.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        preOrder.push_back(tmp);
    }
    vector<int> res = helper(inOrder,preOrder);
    for(auto it=res.begin();it!=res.end();it++){
        if(it==res.begin())
            cout<<*it;
        else{
            cout<<" "<<*it;
        }    
    }
    cout<<endl;
    return 0;
}