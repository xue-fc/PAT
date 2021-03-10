#include<iostream>

using namespace std;

char str[10000];

int main(){
    scanf("%s",str);
    string s = string(str);
    scanf("%s",str);
    string sub = string(str);
    if(s.compare(sub)==0){
        cout<<sub<<endl;
        return 0;
    }
    string res="";
    int maxl=s.size();
    for(auto it=s.begin();it!=s.end()-sub.size()+1;it++){
        if(*it == sub[0]){
            auto lit=it;
            int count=0,i;
            for(i=0;i<maxl-1;i++,lit++){
                if(count==sub.size())
                    break;
                if(*lit==sub[count])
                    count++;
            }
            if(count == sub.size()){
                res = string(it,lit);
                maxl = res.size();
            }
        }
    }
    cout<<res<<endl;
    return 0;
}