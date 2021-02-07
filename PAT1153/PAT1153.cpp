/*
    这个题很难。
    写cmp函数要用引用传参，会快一点，养成好习惯。
    如果不需要map的排序功能，就使用unordered_map，会快一点
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
struct card{
    string raw;
    char level;
    int site_num;
    int date;
    int id;
    int score;
};

bool cmp(const card &a,const card &b){
    if(a.score!=b.score)
        return a.score >= b.score;
    else
        return a.raw < b.raw;
}

bool p_cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}
int main(){
    int N,M;
    string s;
    cin>>N>>M;
    vector<card> testees(N);
    for(int i=0;i<N;i++){
        cin>>s;
        string::iterator it = s.begin();
        testees[i].level = *it;
        it++;
        testees[i].site_num = stoi(string(it,it+3));
        it+=3;
        testees[i].date = stoi(string(it,it+6));
        it+=6;
        testees[i].id = stoi(string(it,it+3));
        int score;
        cin>>score;
        testees[i].score = score;
        testees[i].raw = s + " " + to_string(score);
    }
    for(int i=1;i<=M;i++){
        int type;
        string term;
        cin>>type>>term;
        switch (type)
        {
        case 1 :
        {   
            cout<<"Case "<<i<<": "+to_string(type)+" "+term<<endl;
            vector<card> tmp;
            for(int i=0;i<N;i++){
                if(testees[i].level==term[0])
                    tmp.push_back(testees[i]);
            }
            sort(tmp.begin(),tmp.end(),cmp);
            if(tmp.size()==0)
                cout<<"NA"<<endl;
            for(vector<card>::iterator it=tmp.begin();it!=tmp.end();it++){
                cout<<it->raw<<endl;
            }
            break;
        }
        case 2:
        {
            cout<<"Case "<<i<<": "+to_string(type)+" "+term<<endl;
            int site = stoi(term);
            int sum=0;
            int a=0;
            for(int i=0;i<N;i++){
                if(testees[i].site_num==site)
                {
                    sum += testees[i].score;
                    a++;
                }
            }
            if(a==0)
                cout<<"NA"<<endl;
            else{
                cout<<a<<" "<<sum<<endl;
            }
            break;
        }
        case 3:
        {
            cout<<"Case "<<i<<": "+to_string(type)+" "+term<<endl;
            int date = stoi(term);
            vector<int> sites(1000,0);
            unordered_map<int,int> m;
            bool flag = true;
            for(int i=0;i<N;i++){
                if(testees[i].date==date)
                {
                    if(m.count(testees[i].site_num)==0)
                        m.insert(pair<int,int>(testees[i].site_num,1));
                    else
                        m[testees[i].site_num]++;
                    flag = false;
                }
            }
            if(flag)
            {   
                cout<<"NA"<<endl;
                break;
            }
            vector<pair<int,int>> r;
            for(unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++){
                r.push_back(*it);
            }
            sort(r.begin(),r.end(),p_cmp);
            for(int i=0;i<r.size();i++){
                cout<<r[i].first<<" "<<r[i].second<<endl;
            }
            break;
        }
        }
    }
    return 0;
}
