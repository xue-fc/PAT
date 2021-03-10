#include<iostream>
#include<algorithm>
using namespace std;

bool isprime(string s){
    int tmp = stoi(s);
    if(tmp<=1)
        return false;
    if(tmp==2 || tmp==3)
        return true;
    for(int i=2;i*i<tmp;i++){
        if(tmp% i==0 )
            return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    bool flag = true;
    for(auto it=s.begin();it!=s.end();it++){
        string tmp = string(it,s.end());
        cout<<tmp<<" ";
        if(isprime(tmp)){
            cout<<"Yes\n";
        }
        else{
            flag = false;
            cout<<"No\n";
        }
    }
    if(flag)
        cout<<"All Prime!\n";
    return 0;
}