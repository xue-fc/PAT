#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    int M;
    cin >> M;
    getchar();
    char *token1,*token2;
    vector<string> ID;
    char *saveptr1,*saveptr2;
    vector<int> tmp(3);
    vector<int> min;
    min.push_back(23);
    min.push_back(59);
    min.push_back(59);
    string minID;
    vector<int> max;
    max.push_back(0);
    max.push_back(0);
    max.push_back(0);
    string maxID;

    for(int i=0;i<M;i++){
        cin.getline(str,MAX);
        token1 = strtok_r(str," ",&saveptr1);
        char *tmpID = token1;
        //intime
        token1 = strtok_r(NULL," ",&saveptr1);
        token2 = strtok_r(token1,":",&saveptr2);
        tmp[0] = atoi(token2);
        token2 = strtok_r(NULL,":",&saveptr2);
        tmp[1] = atoi(token2);
        token2 = strtok_r(NULL,":",&saveptr2);
        tmp[2] = atoi(token2);
        if(tmp[0]<min[0])
            {min = vector<int>(tmp);minID=string(tmpID);}
        else if(tmp[0]==min[0] && tmp[1]<min[1])
            {min = vector<int>(tmp);minID=tmpID;}
        else if(tmp[1]==min[1] && tmp[2]<min[2])
            {min = vector<int>(tmp);minID=string(tmpID);}
        //outtime
        token1 = strtok_r(NULL," ",&saveptr1);
        token2 = strtok_r(token1,":",&saveptr2);
        tmp[0] = atoi(token2);
        token2 = strtok_r(NULL,":",&saveptr2);
        tmp[1] = atoi(token2);
        token2 = strtok_r(NULL,":",&saveptr2);
        tmp[2] = atoi(token2);
        if(tmp[0]>max[0])
            {max = vector<int>(tmp);maxID=string(tmpID);}
        else if(tmp[0]==max[0] && tmp[1]>max[1])
            {max = vector<int>(tmp);maxID=string(tmpID);}
        else if(tmp[1]==max[1] && tmp[2]>max[2])
            {max = vector<int>(tmp);maxID=string(tmpID);}
    }
    cout<<minID<<' '<<maxID;
    return 0;
}

