#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

class comp{
    public:
        bool operator()(const string a,const string b) const{
            string as = a.substr(6,14);
            string bs = b.substr(6,14);
            return as < bs;
        }
};


int main(){
    int N;
    cin>>N;
    unordered_set<string> al;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        al.insert(tmp);
    }   
    int M;
    cin>>M;
    set<string,comp> s,t;
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        t.insert(tmp);
        if(al.count(tmp)==1){
            s.insert(tmp);
        }
    }
    if(s.size()!=0)
        cout<<s.size()<<endl<<*s.begin()<<endl;
    else{
        cout<<"0\n"<<*t.begin()<<endl;
    }
    return 0;
}