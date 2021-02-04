#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;


struct student{
    string name;
    string id;
    int grade;
};
bool cmp(student a,student b);

int main(){
    int N;
    string n,t;
    cin>>N;
    vector<student> boys;
    vector<student> girls;
    for(int i=0;i<N;i++){
        student tmp;
        int g;
        cin>>n>>t;
        tmp.name = n;
        cin>>n;
        tmp.id = n;
        cin>>g;
        tmp.grade = g;
        if(t.compare("M")==0)
            boys.push_back(tmp);
        else{
            girls.push_back(tmp);
        }
    }
    sort(boys.begin(),boys.end(),cmp);
    sort(girls.begin(),girls.end(),cmp);
    int d=0;
    bool abs=false;
    if(girls.size()==0){
        cout<<"Absent"<<endl;
        abs=true;
    }
    else
    {
        cout<<girls[girls.size()-1].name<<" "<<girls[girls.size()-1].id<<endl;
    }
    

    if(boys.size()==0)
    {
        abs=true;
        cout<<"Absent"<<endl;
    }
    else{
        cout<<boys[0].name<<" "<<boys[0].id<<endl;
    }
    if(abs) cout<<"NA"<<endl;
    else cout<<girls[girls.size()-1].grade-boys[0].grade<<endl;
    return 0;
}

bool cmp(student a,student b){
    return (a.grade < b.grade);
}