/*

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

int cmax,N,sp,M;
int bikes[510]={0};
int graph[510][510] = {inf};
int dis[510] = {inf};

int main(){
    cin>>cmax>>N>>sp>>M;
    for(int i=1;i<=N;i++){
        scanf("%d",bikes+i);
    }
    int a,b,t;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&a,&b,&t);
        graph[a][b] = graph[b][a] = t;
    }
    dis[0] = 0;
    for(int i=1;i<N;i++){
        dis[i] = graph[0][i];
    }
    

    return 0;
}
