#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    string token;
    char root[3]={'0','1','\000'};
    int v_num,c_num;
    cin.getline(str,MAX);
    v_num = atoi(strtok(str," "));
    c_num = atoi(strtok(NULL," "));
    vector<string> ID,tmp;
    vector<vector<string>> child(c_num,ID);
    map<string,vector<string>> mymap;
    for(int i=0;i<c_num;i++){
        cin.getline(str,MAX);
        token = strtok(str," ");
        string id = token;
        token = strtok(NULL," ");
        int n = stoi(token);
        for(int j=0;j<n;j++){
            token = strtok(NULL," ");    
            child[i].push_back(token);
        }
        mymap.insert(pair<string,vector<string>>(id,child[i]));
    }

    queue<string> d,b;
    d.push(root);
    b.push(root);
    int num=0,all=0;
    while(!d.empty()){
        while(!b.empty())
        {
            if(mymap.count(b.front()) == 0) {
                num++;
                d.pop();
                b.pop();
            }
            else
            {     
                vector<string> tmp = vector<string>(mymap[d.front()]);
                d.pop();b.pop();
                for(int i=0;i<tmp.size();i++){
                    d.push(tmp[i]);
                }
            }
        }
        all += num;
        if(all==v_num - c_num)
            cout<<num;
        else cout<<num<<' ';
        num = 0;
        b = queue<string>(d);
    }
    return 0;
}

