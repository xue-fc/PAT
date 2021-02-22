/*
    把unordered_map换成map不知道会不会超时，但用cout和cin肯定会超时
    最后一个样例是链表为空的情况
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

const int MAX = 1000;

struct entry{
    int v;
    string next;
};
bool cmp(pair<string,entry> &a,pair<string,entry> &b){
    return a.second.v < b.second.v;
}
int main(){
    int N;
    int p;
    string pos;
    cin>>N>>pos;
    unordered_map<string,entry> um;
    bool flag = true;
    for(int i=0;i<N;i++){
        entry t;
        string tmp;
        string tmp2;
        char str[MAX];
        int v;
        scanf("%s",str);
        tmp = string(str);
        scanf("%d",&t.v);
        scanf("%s",str);
        tmp2 = string(str);
        t.next = tmp2;
        um[tmp] = t;
        if(tmp.compare(pos)==0)
            flag = false;
    }
    if(flag){
        cout<<"0 -1"<<endl;
        return 0;
    }
    entry tmp = um[pos];
    vector<pair<string,entry>> m(N+1);
    int i=0;

    while(um.count(tmp.next) > 0){
        m[i] = pair<string,entry>(pos,tmp);
        i++;
        pos = tmp.next;
        tmp = um[tmp.next];       
    }
    m[i] = pair<string,entry>(pos,tmp);
    i++;
    sort(m.begin(),m.begin()+i,cmp);
    for(int j=0;j<i;j++){
        m[j].second.next = m[j+1].first;
    }    
    m[i-1].second.next = "-1";
    cout<<i<<" "<<m.begin()->first<<endl;
    for(auto it=m.begin();it!=m.begin()+i;it++){
        printf("%s %d %s\n",it->first.c_str(),it->second.v,it->second.next.c_str());
    }

    return 0;
}
