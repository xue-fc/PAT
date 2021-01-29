#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
int toll[24];

int main(){
    for(int i=0;i<24;i++){
        cin>>toll[i];
    }
    int N;
    cin >> N;
    char str[MAX];
    char *token1,*token2,*saveptr1,*saveptr2;
    map<string,map<string,int>> mymap;
    for(int i=0;i<N;i++){
        cin.getline(str,MAX);
        token1 = strtok_r(str," ",&saveptr1);
        string id = string(token1);
        token1 = strtok_r(NULL," ",&saveptr1);
        string time = string(token1);
        token1 = strtok_r(NULL," ",&saveptr1);
        string direction = string(token1);
        int d = (direction.compare("on-line") ? 0 : 1);
        map<string,int> tmp;
        if(mymap.count(id) == 0)
        {
            tmp.insert(pair<string,int>(time,d));
            mymap[id] = tmp;
        }
        else{
            tmp = mymap[id];
            tmp.insert(pair<string,int>(time,d));
        }
    }
    for(map<string,map<string,int>>::iterator it=mymap.begin();it!=mymap.end();it++){
        map<string,int> tmp = it->second;
        int a = 0;
        cout<<it->first<<' ';
        for(map<string,int>::iterator it=tmp.begin();it!=tmp.end();it++){
            if(it->second == a)
            {
                if(a==0)
                    continue;
            }
        }
    }

    return 0;
}

void count_cost(string a,string b){
    char *token;
    char str[MAX];
    int start[3];//日时分
    int end[3];
    string month;
    strcpy(str,a.c_str());
    token = strtok(str,":");
    month = string(token);
    for(int i=0;i<3;i++){
        token = strtok(NULL,":");
        start[i] = atoi(token);
    }
    strcpy(str,a.c_str());
    token = strtok(str,":");
    for(int i=0;i<3;i++){
        token = strtok(NULL,":");
        end[i] = atoi(token);
    }

    int minutes=0,cost=0;
    int s = (start[0] - 1)*24*60 + start[1]*60 + start[3];
    int e = (end[0] - 1)*24*60 + end[1]*60 + end[3];
    minutes = s - e;
}

