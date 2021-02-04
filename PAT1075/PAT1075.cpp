/*
    难点在于特别复杂
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

struct stu{
    string id = "99999";
    vector<int> sl;
    int all;
    int acnum=0;
    bool f = false;
};

bool cmp(stu a,stu b){
    if(a.all!=b.all)
        return (a.all > b.all);
    else
    {
        if(a.acnum != b.acnum)
            return (a.acnum > b.acnum);
        else 
            return a.id < b.id;
    }
    
}

int main(){
    int N,K,M;
    cin>>N>>K>>M;
    vector<stu> toll = vector<stu>(N);
    for(int i=0;i<N;i++){
        toll[i].sl = vector<int>(K+1,-2);
    }
    vector<int> fm;
    for(int i=1;i<=K;i++){
        int tmp;
        cin>>tmp;
        fm.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        string id;
        int pid,s;
        cin>>id;
        cin>>pid>>s;
        toll[stoi(id)-1].id = id;
        toll[stoi(id)-1].sl[pid] = (toll[stoi(id)-1].sl[pid] == -2 ? s : max(s,toll[stoi(id)-1].sl[pid]));
    }
    for(int i=0;i<N;i++){
        toll[i].all = 0;
        toll[i].acnum = 0;
        for(int j=1;j<=K;j++){
            toll[i].acnum += (toll[i].sl[j] == fm[j-1] ? 1 :0);
            toll[i].all += max(0,toll[i].sl[j]);
            if(toll[i].sl[j] >= 0)
                toll[i].f = true;
        }
    }
    sort(toll.begin(),toll.end(),cmp);
    int lasts = toll[0].all;
    int lastr = 1;
    for(int i=0;i<N;i++){
        if(!toll[i].f)
            break;
        if(toll[i].all == lasts){
            cout<<lastr;
        }
        else
        {
            cout<<i + 1;
            lastr = i + 1;
            lasts = toll[i].all;
        }
        cout<<" "+toll[i].id<<" "<<toll[i].all;
        for(int j=1;j<=K;j++){
            cout<<" "<<(toll[i].sl[j]==-2 ? "-" : to_string(max(0,toll[i].sl[j])));
        }
        cout<<endl;
    }
    return 0;
}
