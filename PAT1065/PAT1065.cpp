/*
    处理字符串比较复杂
    坑一：如果循环里对string长度进行修改，比如补0，那么for循环条件里别用size，因为会变
    坑二：只有长度一样的纯数字string才能用大于号和小于号比较大小，所以得补0且取绝对值
    坑三：加减法时每次都要把borrow和carry位重置
    坑四：减法时要补零，这个操作很有必要的
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
typedef long long ll;

string add(string a,string b);
string minus1(string a,string b);
string pminus(string a,string b);
string abs(string &n){
    if(n[0]=='-')
        return string(n.begin()+1,n.end());
    else
        return n;
}
int main(){
    int n;
    cin>>n;
    vector<string> ttt;
    for(int i=0;i<n;i++){
        string out = "Case #"+to_string(i+1)+": ";
        string a,b,c,res;
        cin>>a>>b>>c;
        if(a[0]=='-' && b[0]=='-'){
            res = add(string(a.begin()+1,a.end()),string(b.begin()+1,b.end()));
            res = "-" + res;
        }
        if(a[0]=='-' && b[0]!='-'){
            res = minus1(a,b);
        }
        if(a[0]!='-' && b[0]=='-'){
            res = minus1(b,a);
        }
        if(a[0]!='-' && b[0]!='-'){
            res = add(a,b);
        }
        string ares = abs(res);
        string ac = abs(c);
        int asize = ares.size();
        int bsize = ac.size();
        for(int i=0;i<bsize-asize;i++)
            ares = "0" + ares;
        for(int i=0;i<asize-bsize;i++)
            ac = "0" + ac;
        if(ares > ac){//res是否大于c
            if(res[0]=='-')
                out+="false";
            else
                out+="true";
        }
        else{//res绝对值小
            if(c[0]=='-')
                out+="true";
            else
                out+="false";
        }
        out+="\n";
        ttt.push_back(out);
    }
    for(int i=0;i<n;i++){
        cout<<ttt[i];
    }
    return 0;
}

string minus1(string n,string p){
    string absn = string(n.begin()+1,n.end());
    string s="";
    if(absn > p){
        s = pminus(absn,p);
        s = "-"+s;
    }
    else{
        s = pminus(p,absn);
    }
    return s;
}
string pminus(string a,string b){
    //a and b is positive and a>b
    int asize = a.size();
    int bsize = b.size();
    for(int i=0;i<bsize-asize;i++)
        a = "0" + a;
    for(int i=0;i<asize-bsize;i++)
        b = "0" + b;
    string s="";
    int borrow=0;
    for(int i=a.size()-1;i>=0;i--){
        int an = a[i]-'0';
        int bn = b[i]-'0';
        int r;
        if(an+borrow>=bn){
            r = an + borrow - bn;
            borrow = 0;
        }
        else{
            r = an + borrow + 10 -bn;
            borrow = -1;
        }
        s = to_string(r) + s;
    }
    while(s[0]=='0')
        s.erase(s.begin());
    return s;
}
string add(string a,string b){
    int asize = a.size();
    int bsize = b.size();
    for(int i=0;i<bsize-asize;i++)
        a = "0" + a;
    for(int i=0;i<asize-bsize;i++)
        b = "0" + b;
    int c=0;
    string s="";
    for(int i=a.size()-1;i>=0;i--){
        int an = a[i]-'0';
        int bn = b[i]-'0';
        int sum = an + bn + c;
        if(sum/10!=0)
            c = 1;
        else
            c = 0;
        s = to_string(sum%10) + s;
    }
    if(c==1)
        s = "1" + s;
    return s;
}
