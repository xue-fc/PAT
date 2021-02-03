#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;

struct entry{
    string all;
    string id;
    string name;
    int grade;
};

bool cmp1(entry a,entry b);
bool cmp2(entry a,entry b);
bool cmp3(entry a,entry b);

int main(){
    int N,c;
    char str[MAX];
    scanf("%d %d",&N,&c);
    // cin>>N>>c;
    getchar();
    vector<entry> t;
    for(int i=0;i<N;i++){
        entry *tmp = new entry;
        char *token;
        // cin.getline(str,MAX);
        scanf("%[^\n]", str);
        getchar();
        tmp->all = string(str);
        token = strtok(str," ");
        tmp->id = string(token);
        token = strtok(NULL," ");
        tmp->name = string(token);
        token = strtok(NULL," ");
        tmp->grade = atoi(token);
        t.push_back(*tmp);
    }
    switch (c)
    {
    case 1:
        sort(t.begin(),t.end(),cmp1);
        break;
    case 2:
        sort(t.begin(),t.end(),cmp2);
        break;
    case 3:
        sort(t.begin(),t.end(),cmp3);
        break;
    }
    for(vector<entry>::iterator it=t.begin();it!=t.end();it++){
        printf("%s\n",(it->all).c_str());
        // cout<<it->all<<endl;
    }
    return 0;
}

bool cmp1(entry a,entry b){
    return (a.id < b.id);
}

bool cmp2(entry a, entry b){
    if(a.name == b.name){
        return (a.id < b.id);
    }
    else{
        return (a.name < b.name);
    }
}

bool cmp3(entry a,entry b){
    if(a.grade == b.grade){
        return (a.id < b.id);
    }
    else{
        return (a.grade < b.grade);
    }
}