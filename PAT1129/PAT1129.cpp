/*
    运算符重载，注意const的位置
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;

const int MAX = 1000;

struct node{
    int index;
    int num=0;

    node(int i,int n){
        index=i;
        num=n;
    }

    bool operator<(const node &b) const{
        if(this->num==b.num){
            return this->index<b.index;
        }
        else{
            return this->num>b.num;
        }
    }
};

int main(){
    int N,K;
    bool visit[50010]={false};
    scanf("%d%d",&N,&K);
    set<node> s;
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d",&tmp);        
        if(i!=0){
            printf("%d:",tmp);
            auto it=s.begin();
            for(int j=0;j<K && j<s.size();j++,it++){
                printf(" %d",it->index);
            }
            printf("\n");
        }
        if(!visit[tmp]){
            s.insert(node(tmp,1));            
            visit[tmp]=true;
        }
        else{
            for(auto it=s.begin();it!=s.end();it++){
                if(it->index==tmp){
                    int tmpnum=it->num+1;
                    s.erase(it);
                    s.insert(node(tmp,tmpnum));
                    break;
                }
            }   
        }
    }
    return 0;
}
