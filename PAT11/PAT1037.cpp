/*
    排序而已，比较简单，注意调整两个vector的长度即可
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;


int main(){
    int nc,np,tmp;
    cin>>nc;
    vector<int> c,p;
    for(int i=0;i<nc;i++){
        cin>>tmp;
        c.push_back(tmp);
    }
    cin>>np;
    for(int i=0;i<np;i++){
        cin>>tmp;
        p.push_back(tmp);
    }
    for(int i=0;i<np-nc;i++)
        c.push_back(0);
    for(int i=0;i<nc-np;i++)
        p.push_back(0);
    sort(c.begin(),c.end());
    sort(p.begin(),p.end());

    long long sum=0;
    for(int i=0;i<p.size();i++){
        if(c[i]*p[i]<0)
            continue;
        sum+=c[i]*p[i];
    }
    cout<<sum<<endl;
    return 0;
}
