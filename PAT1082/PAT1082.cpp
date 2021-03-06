/*
    把空格统一起来，比如在每个数后面都加空格，处理完后删掉最后一个就行
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;

string h[4]={"Qian ","Bai ","Shi ",""};
string n[10] = {"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
string yiwan[4] = {"","Wan ","Yi ",""};
string helper(string s,bool flag){
    string res="";
    while(s.size()%4!=0){
        s = "0" + s;
    }
    bool lastIsZero=false;
    bool stillHead=true;
    for(auto i=0;i<s.size();i++){
        if(s[i]=='0' && (i==s.size()-1 || s[i+1]=='0'))
            continue;
        if(flag && res.size()==0 && s[i]=='0')
        {   stillHead=false;
            continue;
        }
        if(lastIsZero && s[i]=='0')
            continue;
        lastIsZero = false;
        stillHead = (stillHead && s[i]=='0');
        
        res = res + n[s[i]-'0'] +(s[i]=='0' ? "" : h[i]);     
        // (res.size()==0 ? "" : " ") 
    }
    return res;
}

int main(){
    string num;
    string res="";
    bool flag=true;
    cin>>num;
    if(num.compare("0")==0){
        cout<<"ling"<<endl;
        return 0;
    }
    if(num[0]=='-')
    {    
        flag = false;
        num = string(num.begin()+1,num.end());
    }
    while(num.size()%4!=0) num = "0"+num;
    int tmp = num.size()/4;
    for(int i=0;i<num.size();i=i+4){
        // res = res +(i==num.size()-1 ? "" : yiwan[tmp]+" ");
        if(i!=0)
            res = res + yiwan[tmp];
        res = res + helper(string(num.begin()+i,num.begin()+i+4),(i==0));
        tmp--;
    }
    if(!flag){
        res = "Fu " + res;
    }
    res.erase(res.end()-1);
    cout<<res<<endl;
    return 0;
}
