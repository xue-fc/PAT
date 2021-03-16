#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

struct node{
    int addr;
    int data;
    int next;
    node(){};
    node(int a,int b,int c){
        addr = a;
        data = b;
        next = c;
    }
};

int main(){
    int s,n,k;
    cin>>s>>n>>k;
    unordered_map<int,node> m;
    vector<node> all(n);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        m[a] = node(a,b,c);
        // all[i] = node(a,b,c);
    }
    vector<node> list;
    while(s!=-1){
        list.push_back(m[s]);
        s = m[s].next;
    }
    // for(int i=1;i<=n;i++){
    //     if(s==-1)
    //         break;
    //     list[i] = m[s];
    //     s = list[i].next;
    // }
    auto itk=list.begin()+k-1;
    auto itn=list.end()-1;
    vector<node> res;
    bool flag = true;
    bool knum=true;
    bool nnum=true;
    while(knum || nnum)
    {
        if((flag && knum) || !nnum){
            res.push_back(*itk);
            if(itk==list.begin())
                knum=false;
            else
                itk--;
        }
        else{
            res.push_back(*itn);
            // res[i] = *itn;
            if(itn-list.begin()==k){
                nnum=false;
            }
            else
            {
                itn--;
            }
        }
        flag = !flag;

    }
    if(res.size()==0){
        return 0;
    }
    printf("%05d %d ",res[0].addr,res[0].data);
    for(auto it=res.begin()+1;it!=res.end();it++){
        printf("%05d\n%05d %d ",it->addr,it->addr,it->data);
    }
    printf("-1\n");
    return 0;
}