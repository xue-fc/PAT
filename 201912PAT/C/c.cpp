#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
using namespace std;


int main(){
    // unordered_set<int> s;
    int N,M;
    cin>>N>>M;
    vector< unordered_set<int> > r(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        r[a].insert(b);
        r[b].insert(a);
    }
    int K;
    cin>>K;
    for(int i=1;i<=K;i++){
        int n;
        cin>>n;
        int tmp;
        cin>>tmp;
        bool flag=true;
        unordered_set<int> friends = r[tmp];
        for(int j=1;j<n;j++){
            cin>>tmp;
            if(!flag)
                continue;
            if(friends.count(tmp)==0){
                printf("Area %d needs help.\n",i);
                flag = false;
                continue;;
            }
            unordered_set<int> tmpset=friends;
            for(auto it = r[tmp].begin();it!=r[tmp].end();it++){
                if(tmpset.count(*it)!=0)
                    tmpset.erase(*it);
            }
            for(auto it=tmpset.begin();it!=tmpset.end();it++){
                friends.erase(*it);
            }
        }
        if(!flag)
            continue;
        if(friends.size()!=0){
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto it=friends.begin();it!=friends.end();it++){
                pq.push(*it);
            }
            printf("Area %d may invite more people, such as %d.\n",i,pq.top());
        }
        else{
            printf("Area %d is OK.\n",i);
        }
    }

    return 0;
}