/*
    dijkstra算法，加了cost作为第二排序参考的指标
    这题还存了allpath，前面还有的题要存最短路径数目，都是用同样的思路
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int inf = 1000000;
int dis[510];
int cost[510];
int g_dis[510][510];
int g_cost[510][510];
bool visit[510];
vector<vector<int>> all_path;
int main(){
    int N,M,S,D;
    fill(visit,visit+510,false);
    fill(dis,dis+510,inf);
    fill(cost,cost+510,inf);
    fill(g_dis[0],g_dis[0]+510*510,inf);
    fill(g_cost[0],g_cost[0]+510*510,inf);
    scanf("%d%d%d%d",&N,&M,&S,&D);
    all_path.resize(N);
    for(int i=0;i<M;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&d,&c);
        g_dis[a][b] = g_dis[b][a] = d;
        g_cost[a][b] = g_cost[b][a] = c;
    }
    dis[S] = 0;
    cost[S] = 0;
    all_path[S].push_back(S);
    for(int i=0;i<N;i++){
        int maxd = inf;
        int u=-1;
        for(int j=0;j<N;j++){
            if(!visit[j] && dis[j]<maxd){
                u=j;
                maxd = dis[j];
            }
        }
        if(u==-1)
            break;
        visit[u]=true;
        for(int v=0;v<N;v++){
            if(!visit[v] && dis[v] > dis[u] + g_dis[u][v]){
                dis[v] = dis[u] + g_dis[u][v];
                cost[v] = cost[u] + g_cost[u][v];
                all_path[v] = vector<int>(all_path[u]);
                all_path[v].push_back(v);
            }
            else
            {
                if(!visit[v] && dis[v] == dis[u] + g_dis[u][v]){
                    if(cost[v] > cost[u] +g_cost[u][v]){
                        cost[v] = cost[u]+g_cost[u][v];
                        all_path[v] = vector<int>(all_path[u]);
                        all_path[v].push_back(v);
                    }
                }
            }
        }

    }
    for(auto it=all_path[D].begin();it!=all_path[D].end();it++){
        printf("%d ",*it);
    }
    printf("%d %d\n",dis[D],cost[D]);
    return 0;
}
