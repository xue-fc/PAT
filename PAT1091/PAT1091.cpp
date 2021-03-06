/*
    DFS，比较简单
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
int graph[60][1286][168];

int main(){
    fill(graph[0][0],graph[0][0]+1286*168*60,0);
    int M,N,L,T,volume=0;
    scanf("%d%d%d%d",&M,&N,&L,&T);
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                int tmp;
                scanf("%d",&tmp);
                graph[i][j][k] = tmp;
            }
        }
    }
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                if(graph[i][j][k]==1){
                    queue<int> x,y,z;
                    x.push(i);
                    y.push(j);
                    z.push(k);
                    int size=0;
                    while(x.size()!=0){
                        int curx = x.front();
                        int cury = y.front();
                        int curz = z.front();
                        x.pop();
                        y.pop();
                        z.pop();
                        if(graph[curx][cury][curz]==0)
                            continue;
                        graph[curx][cury][curz]=0;
                        size++;
                        if(curx!=0 && graph[curx-1][cury][curz]==1){
                            x.push(curx-1);
                            y.push(cury);
                            z.push(curz);
                        }
                        if(curx!=L-1 && graph[curx+1][cury][curz]==1){
                            x.push(curx+1);
                            y.push(cury);
                            z.push(curz);
                        }
                        if(cury!=0 && graph[curx][cury-1][curz]==1){
                            x.push(curx);
                            y.push(cury-1);
                            z.push(curz);
                        }
                        if(cury!=M && graph[curx][cury+1][curz]==1){
                            x.push(curx);
                            y.push(cury+1);
                            z.push(curz);
                        }
                        if(curz!=0 && graph[curx][cury][curz-1]==1){
                            x.push(curx);
                            y.push(cury);
                            z.push(curz-1);
                        }
                        if(curz!=N && graph[curx][cury][curz+1]==1){
                            x.push(curx);
                            y.push(cury);
                            z.push(curz+1);
                        }
                    }
                    volume += (size>=T ? size : 0);
                }
            }
        }
    }
    cout<<volume<<endl;
    return 0;
}
