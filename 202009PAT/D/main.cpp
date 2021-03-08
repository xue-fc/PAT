#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int scores[1010][1010];
int vouchers[1010][1010];
// unordered_map< pair<int,int>,pair<int,int> > map;
int i;
int N,M;

vector<vector<int>> paths;
int cnt=0;
vector<int> path;

int main(){
    cin>>N>>M;
    vector<int> degrees(N,0);
    vector<int> tmp;
    vector<vector<int>> edges(N,tmp);
    for(i=0;i<M;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        edges[a].push_back(b);
        degrees[b]++;
        scores[a][b] = c;
        vouchers[a][b] = d;
        // map[pair<int,int>(a,b)] = pair<int,int>(c,d);
    }
    int K;
    cin>>K;
    auto it=find(degrees.begin(),degrees.end(),0);
    bool isConsistent=true;
    int pos=-1;
    int minS=10000;
    int maxV=0;

    if(it==degrees.end()){
        printf("Impossible.\n");
        for(int i=0;i<K;i++){
            printf("Error.\n");
        }
        return 0;
    }
    vector<int> copy_degrees = degrees;
    for(i=0;i<N;i++){
        it = find(copy_degrees.begin(),copy_degrees.end(),0);
        if(it==copy_degrees.end()){
            break;
        }
        int pos = it-copy_degrees.begin();
        *it = -1;
        for(auto it1=edges[pos].begin();it1!=edges[pos].end();it1++){
            copy_degrees[*it1]--;
        }
    }
    if(i!=N){
        printf("Impossible.\n");
        for(i=0;i<K;i++){
            int tmp;
            cin>>tmp;
            if(degrees[tmp]==0){
                printf("You may take test %d directly.\n",tmp);
            }
            else{
                printf("Error.\n");
            }
        }
        return 0;
    }
    printf("Okay.\n");

    vector<int> start;
    for(i=0;i<N;i++){
        if(degrees[i]==0)
            start.push_back(i);
    }
    // vector<int> tmp;
    vector<vector<int>> ttmp(N,tmp);
    vector<vector<vector<int>>> paths(start.size(),ttmp);
    vector<int> dtmp(N,99999);
    vector<vector<int>> dis(start.size(),dtmp);
    vector<int> vtmp(N,0);
    vector<vector<int>> vsum(start.size(),vtmp);
    for(int j=0;j<start.size();j++){
        int s = start[j];
        vector<bool> visited(N,false);
        dis[j][s] = 0;
        vsum[j][s] = 0;
        paths[j][s].push_back(s);
        for(int k=0;k<N;k++){
            int min=9999999;
            int p=-1;
            for(int m=0;m<N;m++){
                if(!visited[m] && dis[j][m]<min)
                {
                    min = dis[j][m];
                    p = m;
                }
            }
            if(p==-1)
                break;
            visited[p] = true;
            for(auto it=edges[p].begin();it!=edges[p].end();it++){
                if(dis[j][*it] > scores[p][*it] + dis[j][p]){
                    dis[j][*it] = scores[p][*it] + dis[j][p];
                    vsum[j][*it] = vouchers[p][*it] + vsum[j][p];
                    paths[j][*it] = paths[j][p];
                    paths[j][*it].push_back(*it);
                }
                else if(dis[j][*it] == scores[p][*it] + dis[j][p] && vsum[j][*it] < vouchers[p][*it] + vsum[j][p]){
                    paths[j][*it] = paths[j][p];
                    paths[j][*it].push_back(*it);
                    vsum[j][*it] = vouchers[p][*it] + vsum[j][p];
                }
            }
        }
    }
    for(int i=0;i<K;i++){
        int tmp;
        cin>>tmp;
        if(degrees[tmp]==0){
            printf("You may take test %d directly.\n",tmp);
            continue;
        }
        int minS=99999;
        int maxV=0;
        vector<int> res;
        for(int j=0;j<start.size();j++){   
            if(dis[j][tmp] < minS){
                minS=dis[j][tmp];
                maxV=vsum[j][tmp];
                res = paths[j][tmp];
            }
            else if(dis[j][tmp]==minS && vsum[j][tmp]>maxV){
                maxV=vsum[j][tmp];
                res = paths[j][tmp];
            }
        }
        for(int j=0;j<res.size();j++){
            if(j==0)
                printf("%d",res[j]);
            else
                printf("->%d",res[j]);
        }
        printf("\n");
    }
    return 0;
}