#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
int s2i(string a);
int main(){

    int N,K;
    cin>>N>>K;
    getchar();
    char str[MAX];
    char *token;
    map<int,int> mymap;
    for(int i=0;i<N;i++){
        cin.getline(str,MAX);
        token = strtok(str," ");
        string tmp = string(token);
        int t = s2i(tmp);
        token = strtok(NULL," ");
        int p_time = atoi(token);
        mymap[t] = p_time*60;
    }
    int t = 8*3600;
    vector<int> win(K,0);
    double all = 0;
    int num=0;
    for(map<int,int>::iterator it = mymap.begin();it!=mymap.end();it++)
    {
        if(it->first >= 17*3600)
        {    
            break;
        }
        num++;
        if(K>0){
            K--;
            all += ( t > it->first ? t - it->first : 0); 
            win[K] = (t < it->first ? it->first : t) + it->second;
            continue;
        }
        else{
            vector<int>::iterator it_l = min_element(win.begin(),win.end());
            if(*it_l > it->first)
            {   
                all += *it_l - it->first;
                (*it_l) += it->second;
            }
            else
            {
                *it_l = it->first + it->second;
            }
            
        }
    }
    double ave = all/60.0; 
    printf("%.1f\n",ave/num);
    return 0;
}

int s2i(string a){
    const char *str = a.c_str();
    char t[MAX],*token,*s;
    int time[3];
    strcpy(t,str);
    
    token = strtok_r(t,":",&s);
    time[0] = atoi(token);
    token = strtok_r(NULL,":",&s);
    time[1] = atoi(token);
    token = strtok_r(NULL,":",&s);
    time[2] = atoi(token);
    
    return (60*time[0] + time[1])*60 + time[2];
}
