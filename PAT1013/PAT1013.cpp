/*
    因为是无向图，邻接矩阵必须存成对称的，不然就成有向图了
    用全局变量会减少传参，做题怎么简单怎么来就行
    dfs计算联通分量个数，即为所求
*/
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10000;

int mv[1010][1010] = {0};
bool visit[1010] = {false};
int n;
void dfs(int s){
    visit[s] = true;
    for(int i=1;i<=n;i++){
        if(mv[s][i]==1 && !visit[i]){
            dfs(i);
        }
    }
    return ;
}

int main(){
    // freopen("C:\\Users\\dell\\Desktop\\code\\cpp\\PAT\\test.txt","r",stdin);
    int m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d",&a);
        scanf("%d",&b);
        mv[a][b] = mv[b][a] = 1;
    }
    for(int i=0;i<k;i++){
        int p;
        fill(visit,visit+1010,false);
        scanf("%d",&p);
        visit[p] = true;
        int num=0;
        for(int j=1;j<=n;j++){
            if(visit[j]==false)
            {
                dfs(j);
                num++;
            }
        }
        printf("%d\n",num-1);
    }

    return 0;
}

