/*
    这个题还是得用字符串来做，用unsigned long long仍然不够长
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
bool is_pnum(string a);
int main(){
    int i,K;
    string s;
    cin>>s>>K;
    for(i=0;i<K;i++){
        if(is_pnum(s))
            break;
        else
        {
            string t = s;
            reverse(t.begin(),t.end());
            int c=0;
            string::iterator itt = t.begin();
            string res="";
            for(string::iterator its=s.begin();its!=s.end();its++,itt++){
                int tn = *itt - '0';
                int sn = *its - '0';
                int sum = (tn+sn+c)%10;
                c = (tn+sn+c)/10;
                res = to_string(sum)+res;
            }
            res = (c==1? to_string(c)+res : res);
            s = res;
        } 
    }
    cout<<s<<endl<<i<<endl;
    return 0;
}

bool is_pnum(string a){
    string b = a;
    reverse(b.begin(),b.end());
    return !a.compare(b);
}