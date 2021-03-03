/*
    这里的G1别用string来处理，那样只能用map来存，很难搞而且会蛮难
    所以将string转成int就可以了
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int inf = 100000;

int visit[1010];
int dis[1010];
int edges[1010][1010];
int res,ave,g_min;
int main(){
    ave = 0;
    g_min = 0;
    res = -1;
    int N,M,K,Ds;
    fill(edges[0],edges[0]+1010*1010,inf);
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    char str[100];
    for(int i=0;i<K;i++){
        int a,b;
        scanf("%s",str);
        if(str[0]=='G'){
            a = N + str[1]-'0';
        }
        else
            a = atoi(str);
        scanf("%s",str);
        if(str[0]=='G'){
            b = N + str[1]-'0';
        }
        else
            b = atoi(str);
        int l;
        scanf("%d",&l);
        edges[a][b] = edges[b][a] = l;
    }
    for(int i=1;i<=M;i++){
        fill(visit,visit+1010,false);   
        fill(dis,dis+1010,inf); 
        int start = N+i;
        dis[start]=0;
        for(int k=0;k<N+M;k++){
            int u=-1,mind=inf;
            for(int j=1;j<=N+M;j++){
                if(!visit[j] && dis[j]<mind){
                    u=j;
                    mind=dis[j];
                }
            }
            if(u==-1)
                break;
            visit[u]=true;
            for(int j=1;j<=M+N;j++){
                if(!visit[j] && dis[j]>dis[u]+edges[u][j]){
                    dis[j] = dis[u]+edges[u][j];
                }
            }
        }
        int l_ave=0,l_min=0;
        bool flag=true;
        for(int m=1;m<=N;m++){
            if(dis[m]>Ds){
                flag=false;
                break;
            }
            l_min = dis[m]>l_min ? dis[m] : l_min;
            l_ave += dis[m];
        }
        if(flag && l_min>g_min)
        {
            res = i+N;
            ave = l_ave;
            g_min = l_min;
        }
        else{
            if(flag && l_min==g_min && l_ave<ave){
                res = i+N;
                ave = l_ave;
                g_min = l_min;
            }
        }
    }
    if(res==-1){
        cout<<"No solution\n";
    }
    else
    {
        cout<<"G"<<res-N<<endl;
        printf("%.1f %.1f",g_min/1.0,(ave/1.0)/N);
    }    
    return 0;
}
