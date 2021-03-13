#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
const int inf = 99999999;
vector<int> dis(1010);
int edges[1010][1010];
bool visited[1010];
unordered_map<int,vector<vector<int>>> paths;
vector<int> path;
vector<int> emptyv;
vector<int> toTest;

int nv,nt;

void f(int s){
    int u=-1;
    int min=inf;
    vector<int> v;
    for(int i=1;i<=nv;i++){
        if(visited[i])
            continue;
        if(dis[i]<min){
            v.clear();
            v.push_back(i);
            u=i;
            min=dis[i];
        }else if(dis[i]==min){
            v.push_back(i);
        }
    }
    if(u==-1)
    {
        if(paths.count(s)==0){
            paths[s] = vector<vector<int>>();
        }
        paths[s].push_back(path);
        return ;
    }
    vector<int> copy_dis = dis;
    for(auto it=v.begin();it!=v.end();it++){
        path.push_back(*it);
        visited[*it] = true;
        for(int i=1;i<=nv;i++){
            if(!visited[i] && dis[i]>dis[*it]+edges[*it][i]){
                dis[i] = dis[*it]+edges[*it][i];
            }
        }
        f(s);
        dis = copy_dis;
        visited[*it]=false;
        path.pop_back();
    }
}


void helper(int s){
    dis[s] = 0;
    f(s);
    dis[s] = inf;
}



int main(){
    fill(visited,visited+1010,false);
    fill(dis.begin(),dis.end(),inf);
    fill(edges[0],edges[0]+1010*1010,inf);
    cin>>nv>>nt;
    for(int i=0;i<nt;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[a][b] = edges[b][a] = w;
    }
    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        paths.clear();
        toTest.resize(nv);
        for(int j=0;j<nv;j++){
            int tmp;
            cin>>tmp;
            toTest[j] = tmp;
        }
        if(paths.count(toTest[0])==0)
            helper(toTest[0]);
        vector<vector<int>> t = paths[toTest[0]];
        bool flag = true;
        for(auto it=t.begin();it!=t.end();it++){
            flag = true;
            for(int j=0;j<nv;j++){
                if((*it)[j]!=toTest[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    
    return 0;
}