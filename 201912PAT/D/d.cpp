#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> a;
vector<int> in;
vector<vector<int>> levels(40,a);

void helper(int level,vector<int> in){
    if(in.size()==0)
        return;
    auto it = min_element(in.begin(),in.end());
    vector<int> left = vector<int>(in.begin(),it);
    vector<int> right = vector<int>(it+1,in.end());
    levels[level].push_back(*it);
    helper(level+1,left);
    helper(level+1,right);
}

int main(){
    int N;
    cin>>N;
    in.resize(N);
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        in[i] = tmp;
    }
    helper(0,in);
    int a=0;
    string res="";
    while(levels[a].size()!=0){
        for(auto it=levels[a].begin();it!=levels[a].end();it++){
            res = res + to_string(*it) + " ";
        }
        a++;
    }
    if(res.size()!=0){
        res.erase(res.end()-1);
    }
    cout<<res<<endl;
    return 0;
}