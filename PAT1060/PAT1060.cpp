/*
    这题就分类讨论，分情况讨论它的次数和有效数字
    有两个点过不了
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<regex>

using namespace std;

const int MAX = 1000;

string helper(string a,unsigned N);

int main(){
    string a,b;
    unsigned N;
    cin>>N>>a>>b;

    string a_res = helper(a,N);
    string b_res = helper(b,N);
    if(a_res.compare(b_res) == 0){
        cout<<"YES "+a_res<<endl;
    }
    else{
        cout<<"NO "+a_res+" "+b_res<<endl;
    }
    return 0;
}

string helper(string a,unsigned N){
    if(a.compare("0")==0)
        return "0";
    string af,at,a_eff;
    string::iterator dot;
    int ae;
    dot = find(a.begin(),a.end(),'.');
    if(dot == a.end()){
        af = a;
        at = "";
    }
    else{
        af = string(a.begin(),dot);
        at = string(dot+1,a.end());
    }
    if(af.compare("0")==0){
        ae = 0;
        for(string::iterator it=at.begin();it!=at.end();it++){
            if(*it=='0')
                ae--;
            else
            {
                if(at.end()-it>N)
                    a_eff = string(it,it+N);
                else
                {
                    a_eff = string(it,at.end());
                }
                break;
            }
        }
    }
    else{
        ae = af.size();
        if(af.size() >= N){
            a_eff = string(af.begin(),af.begin()+N);
        }
        else{
            if(af.size()+at.size()>=N)
                a_eff = af + string(at.begin(),at.begin()+N-af.size());
            else
            {
                a_eff = af + at;
            }
        }
    }
    string res = "0."+a_eff+"*10^"+to_string(ae);
    return res;
}
