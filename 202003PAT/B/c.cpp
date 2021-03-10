#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

bool ise[200000];
bool isl[15];
int main(){
    fill(ise,ise+200000,false);
    int a,b;
    cin>>a>>b;
    ise[a]=true;
    ise[b]=true;
    int N,M;
    scanf("%d%d",&N,&M);
    fill(isl,isl+15,true);
    vector<int> now;
    now.push_back(a);
    now.push_back(b);
    vector<int> tmp(M+1,0);
    vector<vector<int>> players(N+1,tmp);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int tmp;
            scanf("%d",&tmp);
            players[i][j]=tmp;
        }
    }

    for(int j=1;j<=M;j++){
        set<int> loser;
        for(int i=1;i<=N;i++){
            if(!isl[i])
                continue;
            int num = players[i][j];
            bool flag = false;
            for(auto it=now.begin();it!=now.end();it++){
                if(*it==num){
                    loser.insert(i);
                    isl[i]=false;
                    flag=true;
                    break;
                }
                if(ise[*it+num]){
                    flag=true;
                }
            }
            if(!flag){
                loser.insert(i);
                isl[i]=false;
                continue;
            }
            ise[num]=true;
            now.push_back(num);
        }
        if(!loser.empty()){
            for(auto it=loser.begin();it!=loser.end();it++){
                printf("Round #%d: %d is out.\n",j,*it);
            }
            // printf("Round #%d: ",j);
            // for(auto it=loser.begin();it!=loser.end();it++){
            //     printf("%d ",*it);
            // }
            // printf("is out.\n");
        }
    }
    // int cnt=0;
    string res="";
    bool flag=false;
    for(int i=1;i<=N;i++){
        if(isl[i]){
            // cnt++;
            res = res + " " + to_string(i);
        }
    }
    if(res.size()==0){
        printf("No winner.\n");
    }
    else{
        res = "Winner(s):" + res;
        cout<<res<<endl;
    }
    return 0;
}