/*
    配对的方法题里总是很含糊
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

const int MAX = 1000;
char str[MAX];
bool cmp(const pair<string,bool> &a,const pair<string,bool> &b){
    return a.first < b.first;
}
int s2i(string t){
    int num=0;
    num+=stoi(string(t.begin(),t.begin()+2))*3600;
    num+=stoi(string(t.begin()+3,t.begin()+5))*60;
    num+=stoi(string(t.begin()+6,t.begin()+8));
    return num;
}
unordered_map<string,vector<pair<string,bool>>> cars;
unordered_map<string,int> car_time;
vector<pair<string,bool>> park;
int main(){
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        scanf("%s",str);
        string plate = string(str);
        scanf("%s",str);
        string t = string(str);
        scanf("%s",str);
        if(cars.count(plate)==0){
            cars[plate] = vector<pair<string,bool>>();
        }
        if(str[0]=='i'){
            cars[plate].push_back(pair<string,bool>(t,true));
        }
        else{
            cars[plate].push_back(pair<string,bool>(t,false));
        }
    }
    for(auto it=cars.begin();it!=cars.end();it++){
        sort(it->second.begin(),it->second.end(),cmp);
        int a=0;
        for(int i=0;i<it->second.size();){
            if(it->second[i].second){
                if(a==0)
                    a++;
                else{
                    it->second.erase(it->second.begin()+i-1);
                    continue;
                }
            }
            else{
                if(a==1)
                    a--;
                else{
                    it->second.erase(it->second.begin()+i);
                    continue;
                }
            }
            i++;
            if(i%2==0 && i!=0){
                if(car_time.count(it->first)==0){
                    int tmp = s2i(it->second[i-1].first) - s2i(it->second[i-2].first);
                    car_time[it->first] = tmp;
                }
                else{
                    car_time[it->first] += s2i(it->second[i-1].first) - s2i(it->second[i-2].first);
                }
            }
        }
        if(it->second.size()%2 != 0){
            it->second.erase(it->second.end()-1);
        }

        for(auto itv=it->second.begin();itv!=it->second.end();itv++){
            park.push_back(*itv);
        }
    }
    sort(park.begin(),park.end(),cmp);
    int num=0;
    int q_num=K;
    string q_time;
    auto it = park.begin();
    while(q_num>0){
        scanf("%s",str);
        q_time = string(str);
        // bool flag = false;
        for(it;it!=park.end();it++){
            if(it->first > q_time){
                break;
            }
            if(it->second)
                num++;
            else   
                num--;
        }
        printf("%d\n",num);
        q_num--;
    }
    vector<string> res;
    int max=0;
    for(auto it = car_time.begin();it!=car_time.end();it++){
        if(it->second > max){
            res.clear();
            res.push_back(it->first);
            max = it->second;
        }
        else if(it->second == max){
            res.push_back(it->first);
        }
    }
    sort(res.begin(),res.end());
    for(auto it=res.begin();it!=res.end();it++){
        printf("%s ",(*it).c_str());
    }
    string l="";
    int a[3] = {max/3600,(max%3600)/60,max%60};
    for(int i=0;i<3;i++){
        if(i!=0){
            l=l+":";
        }
        if(a[i]<10){
            l = l+"0"+to_string(a[i]);
        }
        else{
            l = l+to_string(a[i]);
        } 
    }
    cout<<l<<endl;
    return 0;
}
