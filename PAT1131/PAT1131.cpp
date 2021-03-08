/*
    极为麻烦，需要记录路径是属于哪条线的，不能记录节点
    这也是图算法的一个要点，判断某个性质是在节点上还是边上，比如权重和颜色等
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
unordered_map<string,int> station2int;
unordered_map<int,string> int2s;
int cnt=0;
int s2int(string station){
    if(station2int.count(station)==0){
        station2int[station] = cnt;
        int2s[cnt] = station;
        cnt++;
    }
    return station2int[station];
}
bool edges[110][110];
bool visited[110];
vector<int> path;
vector<int> local_path;
unordered_map<int,int> dic;//站到线的映射
unordered_map<int,int> dic2;//用于求transfer
int minTransfer=0;
void dfs(int node,const int &des,int t=0){
    if(node==des){
        local_path.push_back(des);
        int transfer=0,last=dic2[local_path[0]];
        for(auto it=local_path.begin();it!=local_path.end();it++){
            if(dic2[*it]==-1)
            {
                if(it==local_path.end()-1)
                    continue;
                else{
                    if(dic2[*(it-1)]!=dic2[*(it+1)])
                        transfer++;
                }
            }
        }
        local_path.pop_back();
        if(path.size()==0 || local_path.size()<path.size()-1)
        {   
            path = local_path;
            path.push_back(des);
            return;
        }
        if(local_path.size()==path.size()-1 && transfer < minTransfer){
            path = local_path;
            path.push_back(des);
            return;
            minTransfer = transfer;
        }
    }
    visited[node] = true;
    local_path.push_back(node);
    for(int i=0;i<cnt;i++){
        if(!visited[i] && edges[i][node]){
            dfs(i,des);
        }
    }
    local_path.pop_back();
    visited[node] = false;
}

int main(){
    fill(edges[0],edges[0]+110*110,false);
    int N;
    scanf("%d",&N);
    vector<vector<int>> lines(N+1);
    for(int i=1;i<=N;i++){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",str);
            int tmp = s2int(string(str));
            lines[i].push_back(tmp);
            int pre;
            if(j!=0){
                pre = lines[i][j-1];
                edges[tmp][pre] = edges[pre][tmp] = true;
            }
            if(dic.count(tmp)==0)
                dic2[tmp] = i;
            else
                dic2[tmp] = -1;
            dic[tmp] = i;
        }
    }
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%s",str);
        string as = string(str);
        scanf("%s",str);
        string bs = string(str);
        int a,b;
        a = s2int(as);
        b = s2int(bs);
        fill(visited,visited+110,false);
        local_path.clear();
        path.clear();
        dfs(a,b);
        string res=to_string(path.size()-1)+"\n";
        int lastStation = a;
        int lastLine=dic[a];//这里有问题
        for(auto it=path.begin();it!=path.end();it++){
            if(*it==b){
                res = res + "Take Line#"+to_string(lastLine)+" from "+int2s[lastStation]+" to "+int2s[b]+".\n";
                continue;
            }  
            if(dic[*it]!=lastLine){
                if(dic2[*it]==-1)
                {
                    if(dic2[*(it+1)!=-1])
                    res = res + "Take Line#"+to_string(lastLine)+" from "+int2s[lastStation]+" to "+int2s[*it]+".\n";
                    lastStation = *it;
                }
                else{
                    res = res + "Take Line#"+to_string(lastLine)+" from "+int2s[lastStation]+" to "+int2s[*(it-1)]+".\n";
                    lastStation = *(it-1);
                }
                lastLine = dic[*it];
            }
            if(*it==b){
                res = res + "Take Line#"+to_string(lastLine)+" from "+int2s[lastStation]+" to "+int2s[b]+".\n";
            }   
        }
        printf("%s",res.c_str());
    }

    return 0;
}
