#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    int N,K;
    char *token;
    cin>>N;
    vector<int> t;
    vector<vector<int>> rank = vector<vector<int>>(N,t);
    vector<int> all;
    map<string,int> tm;
    map<string,int> l[101];
    getchar();
    for(int i=0;i<N;i++){
        cin>>K;
        getchar();
        for(int j=0;j<K;j++){
            cin.getline(str,MAX);
            token = strtok(str," ");
            string tmp = string(token);
            token = strtok(NULL," ");
            int a = atoi(token);
            all.push_back(a);
            rank[i].push_back(a);
            l[a][tmp] = i;
        }
    }
    for(int i=0;i<N;i++){
        sort(rank[i].begin(),rank[i].end());
        reverse(rank[i].begin(),rank[i].end());
    }
    cout<<all.size()<<endl;
    sort(all.begin(),all.end());
    reverse(all.begin(),all.end());
    int last = -1;
    for(vector<int>::iterator it=all.begin();it!=all.end();it++){
        int p = *it;
        if(p==last)
            continue;
        last = p;
        for(map<string,int>::iterator it2=l[p].begin();it2!=l[p].end();it2++){
            // vector<vector<int>> rank = vector<vector<int>>(N,t);
            cout<<it2->first<<' '<<it-all.begin() + 1<<' '<<it2->second + 1<<' ';
            cout<<find(rank[it2->second].begin(),rank[it2->second].end(),*it) - rank[it2->second].begin() + 1<<endl;
        }
    }

    return 0;
}

