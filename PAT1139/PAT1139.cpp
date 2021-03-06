/*
    dfs变种，深度固定了
    注意不要自己找自己就行，一些细节要注意下
    得用string存，用Int的话输出时加上0就行
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

const int MAX = 1000;
char str[MAX];

int N,M;
bool edges[310][310];
bool gender[310];//true男，false女

unordered_map<string,int> id2i;
unordered_map<int,string> i2id;
int cnt=0;
int id2index(string id){
    if(id2i.count(id)==0){
        id2i[id] = cnt;
        i2id[cnt] = id;
        cnt++;
    }
    return id2i[id];
}

vector<string> res;
vector<int> path;
int global;
void dfs(int node,int des,bool flag,int depth){
    if(depth==3){
        if(edges[node][des]){
            string tmp = "";
            string b=i2id[path[0]];
            if(b[0]=='-'){
                b.erase(b.begin());
            }
            tmp = tmp + b;
            tmp = tmp +" ";
            string a=i2id[node];
            if(a[0]=='-'){
                a.erase(a.begin());
            }
            tmp = tmp + a;
            res.push_back(tmp);
        }
        return;
    }
    if(depth==2){
        string tmp = i2id[node];
        if(tmp[0]=='-'){
            tmp.erase(tmp.begin());
        }
        path.push_back(node);
        for(int i=0;i<N;i++){
            if(i==des || i==node || i==global)
                continue;
            if(edges[node][i] && (gender[node]==gender[i])==flag ){
                dfs(i,des,flag,3);
            }
        }
        path.pop_back();
        return;
    }
    if(depth==1){
        for(int i=0;i<N;i++){
            if(i==des || i==global)
                continue;
            if(edges[node][i] && gender[node]==gender[i] ){
                dfs(i,des,flag,2);
            }
        }
        return;
    }
}

int main(){
    int a,b;
    cin>>N>>M;
    fill(edges[0],edges[0]+310*310,false);
    fill(gender,gender+310,false);
    for(int i=0;i<M;i++){
        scanf("%s",str);
        string a = string(str);
        scanf("%s",str);
        string b = string(str);
        int ai=id2index(a);
        int bi=id2index(b);
        edges[ai][bi] = edges[bi][ai] = true;
        gender[ai] = (a[0]!='-');
        gender[bi] = (b[0]!='-');
    }
    int K;
    cin>>K;
    bool flag;
    N = cnt;
    for(int i=0;i<K;i++){
        res.clear();
        path.clear();
        scanf("%s",str);
        string a = string(str);
        scanf("%s",str);
        string b = string(str);
        flag = ((a[0]!='-' && b[0]!='-') || (a[0]=='-' && b[0]=='-'));//true是同性
        global = id2index(a);
        dfs(global,id2index(b),flag,1);
        sort(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(auto it=res.begin();it!=res.end();it++){
            printf("%s\n",(*it).c_str());
        }
    }
    return 0;
}
