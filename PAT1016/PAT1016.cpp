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
int count_cost(string a,string b);
int count(int a[3],int b[3]);

int main(){
    int tmp;
    for(int i=0;i<24;i++){
        cin>>tmp;
        toll[i] = tmp;
    }
    int N;
    cin >> N;
    getchar();
    char str[MAX];
    char *token;
    map<string,map<string,int>> mymap;
    string month;
    for(int i=0;i<N;i++){
        cin.getline(str,MAX);
        token = strtok(str," ");
        string id = string(token);
        token = strtok(NULL," ");
        string time = string(token);
        month = string(time.begin(),time.begin()+2);
        time.erase(time.begin(),time.begin()+3);
        token = strtok(NULL," ");
        string direction = string(token);
        int d = (direction.compare("on-line")==0 ? 0 : 1); //compare查下
        map<string,int> tmp;
        if(mymap.count(id) == 0)
        {
            tmp.insert(pair<string,int>(time,d));
            mymap[id] = tmp;
        }
        else{
            mymap[id].insert(pair<string,int>(time,d));
        }
    }
    for(map<string,map<string,int>>::iterator it=mymap.begin();it!=mymap.end();it++){
        map<string,int> tmp = it->second;
        while(1)
        {
            int a=0;
            bool flag = true;
            for(map<string,int>::iterator it=tmp.begin();it!=tmp.end();it++){
                if(it->second != a)
                {
                    if(it->second == 0){
                        if(it==tmp.begin())
                            tmp.erase(it);
                        else{
                            it--;
                            tmp.erase(it);
                        }
                    }
                    else{
                        tmp.erase(it);
                    }
                    flag = false;
                    break;
                }
                a = (a==0 ? 1 : 0);
            }
            if(flag)
                break;
        }
        if(tmp.size()==1 || tmp.size()==0)
            continue;
        cout<<it->first<<" "<<month<<endl;
        int total = 0;
        map<string,int>::iterator it1=tmp.begin();
        map<string,int>::iterator it2=tmp.begin();it2++;
        while(it2!=tmp.end())
        {
            if(it1->second==0)
                total += count_cost(it1->first,it2->first);
            it1++;
            it2++;
        }
        cout<<"Total amount: $";
        printf("%.2f\n",total/100.0);
    }

    return 0;
}

int count_cost(string a,string b){
    string res = a + " " + b + " ";
    char *token;
    char str[MAX];
    int start[3];//日时分
    int end[3];
    strcpy(str,a.c_str());
    token = strtok(str,":");
    
    for(int i=0;i<3;i++){
        start[i] = atoi(token);
        token = strtok(NULL,":");
    }
    strcpy(str,b.c_str());
    token = strtok(str,":");
    for(int i=0;i<3;i++){
        end[i] = atoi(token);
        token = strtok(NULL,":");
    }

    int minutes=0;
    int s = (start[0] - 1)*24*60 + start[1]*60 + start[2];
    int e = (end[0] - 1)*24*60 + end[1]*60 + end[2];
    minutes = e - s;
    int total = count(start,end);
    res += to_string(minutes) + " $";

    cout<<res;
    printf("%.2f\n",total/100.0);
    return total;
}

int count(int a[3],int b[3]){
    if(a[0] != b[0]){
        int tmp[3] = {a[0],23,60};
        int t[3] = {a[0]+1,0,0};
        return count(a,tmp) + count(t,b);
    }
    else if(a[1] != b[1]){
        int tmp[3] = {a[0],a[1],60};
        int t[3] = {a[0], a[1]+1 ,0 };
        return count(a,tmp) + count(t,b);
    }
    else{
        return toll[a[1]] * (b[2] - a[2]);
    }
}

