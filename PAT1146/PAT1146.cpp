/*
    拓扑排序，复习下知识点即可
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


int main(){
    int N,M;
    cin>>N>>M;
    vector<int> degrees(N+1,0);
    vector<int> tmp;
    vector<vector<int>> edges(N+1,tmp);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        degrees[b]++;
    }
    int K;
    cin>>K;
    string res="";
    for(int i=0;i<K;i++){
        vector<int> local(degrees);
        bool flag=false;
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            if(local[tmp]!=0)
                flag = true;
            for(auto it=edges[tmp].begin();it!=edges[tmp].end();it++){
                local[*it]--;
            }
        }
        if(flag){
            if(res.size()==0) res = res + to_string(i);
            else res = res + " " + to_string(i);
        }
    }
    cout<<res<<endl;
    return 0;
}
