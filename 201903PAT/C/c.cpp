#include<iostream>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int edges[1010][1010];

int main(){
    fill(edges[0],edges[0]+1010*1010,0);
    int K,N,M;
    cin>>K>>N>>M;
    for(int i=0;i<M;i++){
        int c,r,d;
        scanf("%d%d%d",&c,&r,&d);
        edges[c][r] += d;
    }
    vector<int> crime;
    for(int i=1;i<=N;i++){
        int num=0;
        unordered_set<int> tmp;
        for(int j=1;j<=N;j++){
            if(edges[i][j]!=0 && edges[i][j] <= 5)
            {
                tmp.insert(j);
                num++;
            }
        }
        if(num>K){
            int callBack=0;
            for(auto it=tmp.begin();it!=tmp.end();it++){
                if(edges[*it][i]!=0)
                    callBack++;
            }
            if(callBack*5 <= num){
                crime.push_back(i);
            }
        }
    }
    if(crime.size()==0){
        cout<<"None\n";
        return 0;
    }
    while(1){
        vector<int> gang;
        auto lead=crime.begin();
        while(lead!=crime.end() && *lead==-1 )
            lead++;
        if(lead==crime.end())
            break;
        gang.push_back(*lead);
        queue<int> q;
        q.push(*lead);
        *lead = -1;
        bool flag=true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto it=crime.begin();it!=crime.end();it++){
                if(*it==-1)
                    continue;
                if(edges[*it][t]!=0 && edges[t][*it]!=0)
                {
                    gang.push_back(*it);
                    q.push(*it);
                    *it = -1;
                }
            }
        }
        sort(gang.begin(),gang.end());
        cout<<gang[0];
        for(auto it=gang.begin()+1;it!=gang.end();it++){
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}