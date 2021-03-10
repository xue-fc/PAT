#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<unordered_map>
using namespace std;

char str[10000];

vector<string> res;

struct node{
    int id;
    vector<node> children = vector<node>();

    node(int i){
        id = i;
    }
};
bool visit[10000];
vector<int> path;
vector<node*> cur;
unordered_map<int,string> um;
void dfs(node r,const int des){
    path.push_back(r.id);
    if(visit[r.id]){
        string res = "0000";
        // printf("0000");
        for(auto it=path.begin()+1;it!=path.end();it++){
            res = res + "->";
            string tmp=to_string(*it);
            while(tmp.size()<4)
                tmp = "0"+tmp;
            res = res+tmp;
            // printf("->%04d",*it);
        }
        res = res+"\n";
        um[r.id] = res;    
        visit[r.id]=false;
    }
    for(auto it=r.children.begin();it!=r.children.end();it++){
        dfs(*it,des);
    }
    path.pop_back();
    return;
}

int main(){
    fill(visit,visit+10000,false);
    int N;
    cin>>N;
    node root = node(0);
    cur.push_back(&root);
    scanf("%s",str);
    getchar();
    for(int i=0;i<N-1;i++){
        int cnt=0;
        char lc=' ';
        while(lc==' ')
        {
            scanf("%c",&lc);
            cnt++;
        }
        scanf("%s",str+1);
        getchar();
        str[0] = lc;
        auto it=cur.begin();
        it += cnt-2;
        int id = atoi(str);
        node tmp = node(id);
        (*it)->children.push_back(tmp);
        cur.erase(it+1,cur.end());
        cur.push_back( &(*( (*it)->children.end()-1)));
    }
    int K;
    cin>>K;
    vector<int> tos(K);
    for(int i=0;i<K;i++){
        int tmp;
        scanf("%d",&tmp);
        visit[tmp]=true;
        tos[i]=tmp;
    }
    dfs(*cur[0],1);
    for(int i=0;i<K;i++){
        if(um.count(tos[i])==0){
           printf("Error: %04d is not found.\n",tos[i]); 
        }
        else{
            printf(um[tos[i]].c_str());
        }
    }
    return 0;
}