#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
const int inf =99999999;
int edges[210][210];
bool visited[210];
int dis[210][210];
int main(){
    fill(edges[0],edges[0]+210*210,inf);
    fill(dis[0],dis[0]+210*210,inf);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b] = edges[b][a] = c;
    }
    for(int i=0;i<=N;i++){
        fill(visited,visited+210,false);
        // visited[i]=true;
        dis[i][i]=0;
        while(1){
            int min = inf;
            int u=-1;
            for(int j=0;j<=N;j++){
                if(!visited[j] && dis[i][j] < min){
                    u=j;
                    min = dis[i][j];
                }
            }
            if(u==-1)
                break;
            visited[u]=true;
            for(int j=0;j<=N;j++){
                if(!visited[j] && dis[i][j] > dis[i][u] + edges[u][j]){
                    dis[i][j] = dis[i][u] + edges[u][j];
                }
            }
        }
    }
    fill(visited,visited+210,false);
    int cur=0;
    vector<int> path;
    path.push_back(0);
    int sum=0;
    while(1){
        visited[cur] = true;
        int u=-1;
        int min=inf;
        for(int i=0;i<=N;i++){
            if(!visited[i] && dis[cur][i] < min){
                u = i;
                min = dis[cur][i];
            }
        }
        if(u==-1)
            break;
        path.push_back(u);
        sum += min;
        cur = u;
    }
    string res="";
    for(auto it=path.begin();it!=path.end();it++){
        res = res + to_string(*it) + " ";
    }
    res.erase(res.end()-1);
    cout<<res<<endl;
    res = "";
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            res = res + to_string(i) + " ";
        }
    }
    if(res.size()!=0){
        res.erase(res.end()-1);
        cout<<res<<endl;
    }
    else{
        cout<<sum<<endl;
    }
    return 0;
}