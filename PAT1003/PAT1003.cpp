/*
    必须用fill对数组进行初始化，不能在声明的时候来，那样不知道为啥有问题
    这题是dijkstra算法，有两个排序变量已经要记录最短路径条数，是个改进版本
    图用邻接矩阵存储
*/
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

const int inf = 10000;


int main(){
    int n,m,c1,c2;
    int rteams[510] = {0};
    int graph[510][510] = {inf};
    int dis[510] = {inf};
    fill(dis,dis+510,inf);
    fill(graph[0],graph[0]+510*510,inf);
    int w[510] = {0};
    int num[510] = {0};
    bool visit[510] = {false};
    fill(visit,visit+510,false);
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++){
        scanf("%d",rteams+i);
    }
    int a,b,length;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&length);
        graph[a][b] = graph[b][a] = length;
    }

    //dijkstra算法


    dis[c1] = 0;
    w[c1] = rteams[c1];//救援队数目
    num[c1] = 1;//最短路径条数
    for(int i=0;i<n;i++){
        int u=-1;
        int min = inf;
        for(int j=0;j<n;j++){
            if(!visit[j] && dis[j]<min){
                u = j;
                min = dis[j];
            }
        }
        if(u==-1)
            break;
        visit[u] = true;
        for(int v=0;v<n;v++){
            if(!visit[v] && graph[u][v]!=inf){//没被访问过，而且有边
                if(dis[v] == dis[u] + graph[u][v]){
                    num[v] = num[u] + num[v];//距离相等了，最短路径要加加
                    if(w[v] < w[u] + rteams[v]){
                        w[v] = w[u] + rteams[v];
                    }
                }
                else if(dis[v] > dis[u] + graph[u][v]){ //距离更短，就更新信息
                    num[v] = num[u];
                    w[v] = w[u] + rteams[v];
                    dis[v] = dis[u] + graph[u][v];
                }
            }
        }
    }
    cout<<num[c2]<<" "<<w[c2]<<endl;
    return 0;
}