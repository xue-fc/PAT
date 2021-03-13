#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

struct node{
    int addr;
    int v;
    int next;

    node(){};
    node(int a,int b,int c){
        addr = a;
        v = b;
        next = c;
    }
};

int main(){
    unordered_map<int,node> m;
    int l,s,N;
    cin>>l>>s>>N;
    for(int i=0;i<N;i++){
        int addr,v,next;
        cin>>addr>>v>>next;
        m[addr] = node(addr,v,next);
    }
    vector<node> lv,sv;
    int start = l;
    while(start!=-1){
        node tmp = m[start];
        lv.push_back(m[start]);
        start = tmp.next;
    }
    start = s;
    while(start!=-1){
        node tmp = m[start];
        sv.push_back(m[start]);
        start = tmp.next;
    }
    if(lv.size()<sv.size()){
        vector<node> tmp;
        tmp = sv;
        sv = lv;
        lv = tmp;
    }
    auto rsit=sv.rbegin();
    auto lit = lv.begin();
    int cnt=1,i;
    int all = sv.size()+lv.size();
    vector<node> res(all);
    for(i=0;i<all && lit!=lv.end() && rsit!=sv.rend();i++){
        if((i+1)%3 != 0){
            res[i] = *lit;
            lit++;
        }
        else{
            res[i] = *rsit;
            rsit++;
        }
        // i++;
    }
    for(;lit!=lv.end();lit++){
        res[i] = *lit;
        i++;
    }
    for(;rsit!=sv.rend();rsit++){
        res[i] = *rsit;
        i++;
    }
    printf("%05d %d",res[0].addr,res[0].v);
    for(i=1;i<all;i++){
        printf(" %05d\n%05d %d",res[i].addr,res[i].addr,res[i].v);
    }
    printf(" -1\n");
    return 0;
}