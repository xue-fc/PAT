#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    char *token;
    int M,N;
    cin>>N>>M;
    getchar();
    map<string,vector<int>> grades;
    vector<int> t;
    vector<vector<int>> all(4,t);
    for(int i=0;i<N;i++){
        int tmp,sum=0;
        string id;
        vector<int> g;
        cin.getline(str,MAX);
        token = strtok(str," ");
        id = string(token);
        for(int j=0;j<3;j++){
            token = strtok(NULL," ");
            tmp = atoi(token);
            sum += tmp;
            g.push_back(tmp);
            all[j+1].push_back(tmp);
        }
        all[0].push_back(sum/3);
        g.insert(g.begin(),sum/3);
        grades[id] = g;
    }    

    for(int i=0;i<4;i++){
        sort(all[i].begin(),all[i].end());
        reverse(all[i].begin(),all[i].end());
    }
    char course[4] = {'A','C','M','E'};
    vector<string> ids;
    for(int i=0;i<M;i++){
        cin.getline(str,MAX);
        ids.push_back(string(str));
    }
    for(int i=0;i<M;i++){
        string id = ids[i];
        int rank[4];
        if(grades.count(id) == 0)
        {
            cout<<"N/A"<<endl;
            continue;
        }
        for(int j=0;j<4;j++)
        {
            int pos = find(all[j].begin(),all[j].end(),grades[id][j]) - all[j].begin();
            rank[j] = pos + 1;
        }
        cout<<*min_element(rank,rank+4)<<' '<<course[ min_element(rank,rank+4)-rank ]<<endl;
    }

    return 0;
}

