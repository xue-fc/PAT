/*
    有向图用邻接表可能好一点，这里用邻接矩阵给超时了
    BFS用队列，这里要控制层数所以可以用两个队列
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;
int N,L;
int edges[1010][1010];
bool visited[1010];
int main(){
    cin>>N>>L;
    int n;
    fill(edges[0],edges[0]+1010*1010,0);
    for(int i=1;i<=N;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            edges[i][tmp] = 1;
        }
    }
    scanf("%d",&n);
    int q;
    for(int i=0;i<n;i++){
        scanf("%d",&q);
        fill(visited,visited+1010,false);
        int num=0;
        visited[q] = true;
        queue<int> nodes;
        nodes.push(q);
        for(int j=0;j<L;j++){
            queue<int> tmp;
            while(!nodes.empty()){
                int cur=nodes.front();
                nodes.pop();
                for(int k=1;k<=N;k++){
                    if(edges[k][cur]==1 && !visited[k])
                    {
                        tmp.push(k);
                        visited[k]=true;
                    }
                }
            }
            nodes = tmp;
            num += nodes.size(); 
        }
        printf("%d\n",num);
    }
    return 0;
}
