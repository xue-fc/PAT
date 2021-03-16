#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<string,string> m; 
vector< pair<string,int> > l;

bool comp(pair<string,int> &a,pair<string,int> &b){
    if(a.first==b.first)
    {
        if(a.second==1)
            return true;
        else
            return false;
    }
    else
        return a.first < b.first;
}

int main(){
    int N;
    cin>>N;
    string enter,exit;
    for(int i=0;i<N;i++){
        cin>>enter>>exit;
        m[enter] = exit;
        l.push_back(pair<string,int>(enter,1));
        l.push_back(pair<string,int>(exit,0));
    }
    sort(l.begin(),l.end(),comp);
    int cnt=0;
    string exitTime = "00:00:00";
    for(auto it=m.begin();it!=m.end();it++){
        auto a = find(l.begin(),l.end(),pair<string,int>(it->first,1));
        auto b = find(l.begin(),l.end(),pair<string,int>(it->second,0));
        int outnum=0,innum=0;
        // if(a==l.end())
        //     break;

        for(auto it=a+1;it!=b;it++){
            if(it->second==-1)
                continue;
            if(it->second==0)
                outnum++;
            if(it->second==1)
                innum++;
        }
        if(innum>=1){
            // l.erase(b);
            // l.erase(a);
            b->second = -1;
            continue;
        }
        if(it->first >= exitTime){
            cnt++;
            exitTime = it->second;
            // l.erase(a);
            // l.erase(b);
            b->second = -1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}