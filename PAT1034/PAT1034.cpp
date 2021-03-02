/*
    排序而已，比较简单，注意调整两个vector的长度即可
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;

const int MAX = 1000;
unordered_map<string,int> s2i;
unordered_map<int,string> i2s;
int id=0;
int N,K;
int edges[1010][1010]={0};
bool visit[1010];
int weight[1010];
int string2int(string s){
    if(s2i.count(s)==0){
        s2i[s] = id;
        i2s[id] = s;
        id++;
    }
     return s2i[s];
}


void dfs(int node,int &head,int &num,int &totalweight){
    if(!visit[node]){
        visit[node] = true;
        totalweight += weight[node];
        num++;
        if(head==-1 || weight[node]>weight[head])
            head = node;
        for(int i=0;i<N;i++){
            if(edges[node][i]!=0){
                dfs(i,head,num,totalweight);
            }
        }
    }
    return;
}

int main(){
    string a,b;
    int time;
    char str[1000];
    fill(visit,visit+1010,false);
    fill(weight,weight+1010,0);
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%s",str);
        a = string(str);
        scanf("%s",str);
        b = string(str);
        scanf("%d",&time);
        int ai = string2int(a);
        int bi = string2int(b);

        edges[ai][bi] += time;
        edges[bi][ai] += time;
        weight[ai] += time;
        weight[bi] += time;
    }
    N=id;
    int maxweight=K;
    set<string> heads;
    for(int i=0;i<N;i++){
        int head=-1,num=0,totalweight;
        if(!visit[i]){
            totalweight=0;
            dfs(i,head,num,totalweight);
            
            if(num>2 && totalweight > 2*K){
                // heads.clear();
                heads.insert(i2s[head]+" "+to_string(num));
                // maxweight = totalweight;
            }
            // else if(totalweight==maxweight){
            //     heads.insert(i2s[head]+" "+to_string(num));
            // }
        }
    }
    cout<<heads.size()<<endl;
    for(auto it=heads.begin();it!=heads.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
