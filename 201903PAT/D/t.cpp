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
    string a = "1234567";
    cout<<a.substr(1,2)<<endl;
    cout<<a.substr(1)<<endl;
    cout<<a.substr(2)<<endl;
    cout<<a.substr(a.size()-1)<<endl;
    // cout<<a.substr(1)<<endl;
    return 0;
}