#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;

int main(){
    int N;
    cin>>N;
    char str[MAX];
    string id,k;
    vector<string> res;
    for(int i=0;i<N;i++){
        cin>>id>>k;
        bool flag,f=true;
        for(string::iterator it=k.begin();it!=k.end();it++){
            flag = true;
            switch (*it)
            {
            case '1':
                *it='@';
                break;
            case '0':
                *it='%';break;
            case 'l':
                *it='L';break;
            case 'O':
                *it='o';break;
            default :
                flag = false;
                break;
            }
            if(flag)
                f=false;
        }
        if(!f){
            res.push_back(id + " " + k);
        }
    }
    if(res.size()!=0)
    {
        cout<<res.size()<<endl;
        for(vector<string>::iterator it=res.begin();it!=res.end();it++){
            cout<<*it<<endl;
        }
    }
    if(res.size()==0 && N==1){
        cout<<"There is 1 account and no account is modified"<<endl;
    }
    if(res.size()==0 && N>1){
        cout<<"There are"<< N << "accounts and no account is modified"<<endl;
    }
    return 0;
}
