#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct node{
    int addr;
    int value;
    int next;

    node(){};

    node(int c,int a,int b){
        addr = c;
        value = a;
        next = b;
    }
};

struct Knodes{
    private:
        int K;
    public:
        vector<node> nodes;

    Knodes(int k){
        K=k;
    }
};

unordered_map<int,node> m;
vector<Knodes> res;
int main(){
    int start,N,K;
    cin>>start>>N>>K;
    for(int i=0;i<N;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        m[a] = node(a,b,c);
    }
    while(start!=-1){
        Knodes t(K);
        for(int i=0;i<K;i++){
            if(start==-1)
                break;
            node now = m[start];
            t.nodes.push_back(now);
            start = now.next;
        }
        res.push_back(t);
    }
    string last="";
    bool flag=false;
    for(auto it=res.rbegin();it!=res.rend();it++){
        for(auto lit=it->nodes.begin();lit!=it->nodes.end();lit++){
            if(flag){
                // last = last + to_string(lit->addr);
                printf("%05d\n",lit->addr);
                // cout<<last<<endl;
                // last.clear();
            }
            printf("%05d %d ",lit->addr,lit->value);
            flag = true;
        }
    }
    if(flag){
        printf("-1\n");
    }
    return 0;
}