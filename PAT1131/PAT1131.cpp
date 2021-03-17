/*
    著名的北京地铁
    最多会有10000个点，用邻接矩阵会内存超限，晴神是复用了int类来节省空间
    要注意是边属于几号线而不是点属于，记得区分哪些性质是边的哪些性质是点的
    因为存不下1000个，所以使用mao当字典，来把序号毫无关系的站映射成连续的，这样起码可以过前几个点
    dfs时思路也挺简单，改过的值记得还原，然后到终点时使用下即可
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

const int MAX = 5;
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
int edges[4000][4000];
bool visited[4000];
vector<int> path;
vector<int> local_path;
int minTransfer=9999;
int transfer=0;
int lastline=0;
void dfs(int node,const int &des,int t=0){
    if(node==des){
        if(path.size()==0 || local_path.size()+1<path.size() || (local_path.size()+1==path.size() && transfer<minTransfer))
        {   
            path = local_path;
            minTransfer = transfer;
            path.push_back(des);
        }
        return;
    }
    visited[node] = true;
    local_path.push_back(node);
    for(int i=0;i<cnt;i++){
        if(!visited[i] && edges[i][node]!=-1){
            if(edges[node][i] != lastline)
            {
                int tmp = lastline;
                lastline = edges[node][i];
                transfer++;
                dfs(i,des);
                transfer--;
                lastline = tmp;
            }   
            else
                dfs(i,des); 
        }
    }
    local_path.pop_back();
    visited[node] = false;
}

int main(){
    fill(edges[0],edges[0]+4000*4000,-1);
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
                edges[tmp][pre] = edges[pre][tmp] = i;
            }
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
        fill(visited,visited+4000,false);
        local_path.clear();
        path.clear();
        dfs(a,b);
        cout<<path.size()-1<<endl;
        int lastStation = path[0];
        int lastLine=edges[path[0]][path[1]];
        for(auto it=path.begin();it!=path.end();it++){
            if(*it==b){
                printf("Take Line#%d from %s to %s.\n",lastLine,int2s[lastStation].c_str(),int2s[*it].c_str());
                break;
            }  
            int line = edges[*it][*(it+1)];
            if(line!=lastLine){
                printf("Take Line#%d from %s to %s.\n",lastLine,int2s[lastStation].c_str(),int2s[*it].c_str());
                lastStation = *it;
                lastLine = line;
            }
        }
    }
    return 0;
}
