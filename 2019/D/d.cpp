#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

const int inf = 888888888;

int edges[1020][1020];
int dis[20][1010];
int main(){
    fill(edges[0],edges[0]+1020*1020,inf);
    fill(dis[0],dis[0]+1010*20,inf);
    int Ns,Na;
    cin>>Ns>>Na;
    vector<int> ava(Na+1);
    for(int i=1;i<=Na;i++){
        int tmp;
        scanf("%d",&tmp);
        ava[i] = tmp;
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        string str;
        cin>>str;
        if(str[0]=='A')
            a = Ns + stoi(str.substr(2));
        else
            a = stoi(str);
        cin>>str;
        if(str[0]=='A')
            b = Ns + stoi(str.substr(2));
        else
            b = stoi(str);    
        scanf("%d",&c);
        edges[a][b] = edges[b][a] = c;
    }
    int visited[1020];
    fill(visited,visited+1020,false);
    vector<int> path;
    vector<vector<int>> paths(Na+Ns+1,path);
    vector<vector<vector<int>>> allpath(Na+1,paths);
    vector<int> c(Na+Ns+1);
    vector<vector<int>> count(Na+1,c);
    for(int i=1;i<=Na;i++){
        fill(visited,visited+1020,false);
        count[i][i+Ns] = 0;
        dis[i][i+Ns] = 0;
        allpath[i][i+Ns].push_back(i+Ns);
        while(1){
            int u=-1;
            int min = inf;
            for(int j=1;j<=Ns+Na;j++){
                if(!visited[j] && dis[i][j] < min){
                    min = dis[i][j];
                    u=j;
                }
            }
            if(u==-1)
                break;
            visited[u] = true;
            for(int j=1;j<=Ns+Na;j++){
                if(!visited[j] && dis[i][j] > edges[u][j] + dis[i][u]){
                    dis[i][j] = edges[u][j] + dis[i][u];
                    count[i][j] = count[i][u] + 1;
                    allpath[i][j].clear();
                    allpath[i][j] = allpath[i][u];
                    allpath[i][j].push_back(j);
                }
            }
        }
    }

    int K;
    cin>>K;
    bool flag=true;
    for(int i=0;i<K;i++){
        int tmp;
        cin>>tmp;
        if(!flag)
        {
            printf("All Busy\n");
            continue;
        }
        int u=-1;
        int min=inf;
        int maxava = 0;
        int mincount=9999;
        for(int j=1;j<=Na;j++){
            if(ava[j]!=0 && dis[j][tmp] < min){
                min = dis[j][tmp];
                maxava = ava[j];
                mincount = count[j][tmp];
                u=j;
            } else if(ava[j]>maxava && dis[j][tmp]==min && ava[j]!=0){
                maxava = ava[j];
                mincount = count[j][tmp];
                u=j;
            } else if(ava[j]!=0 && ava[j]==maxava && dis[j][tmp]==min && count[j][tmp]<mincount){
                mincount = count[j][tmp];
                u=j;
            }
        }
        if(u==-1)
        {
            printf("All Busy\n");
            flag = false;
            continue;
        }
        ava[u] = ava[u] - 1;
        vector<int> path = allpath[u][tmp];
        for(auto it=path.begin();it!=path.end();it++){
            if(it!=path.begin())
                printf(" ");
            if(*it>Ns)
                printf("A-%d",*it-Ns);
            else
                printf("%d",*it);
        }
        printf("\n%d\n",min);
    }
    return 0;
}