#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
string helper(int a);
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"#"<<helper(a)<<helper(b)<<helper(c)<<endl;
    return 0;
}

string helper(int a){
    if(a==0)
        return string("00");
    string t="";
    while(a!=0)
    {
        int tmp = a%13;
        a = a/13;
        if(tmp<10)
            t = t + to_string(tmp);
        else
        {
            char str[2] = {'A','\000'};
            str[0] = 'A' + tmp-10;
            t += string(str);
        }
    }
    reverse(t.begin(),t.end());
    if(t.size()==1)
        t = "0" + t;
    return t;
}
