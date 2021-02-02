#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    cin.getline(str,MAX);
    string num = string(str);
    string after = string(str);
    int add = 0;
    for(string::reverse_iterator it = after.rbegin();it!=after.rend();it++){
        if((*it - '0')*2 + add >= 10){
            *it = ((*it - '0')*2 + add - 10) + '0';
            add = 1;
        }
        else
        {   
            *it = (*it - '0')*2 + add + '0';
            add = 0;
        }
    }
    if(add==1)
        after.insert(after.begin(),1,'1');
    string tmp = string(after);
    sort(after.begin(),after.end());
    sort(num.begin(),num.end());
    if(after.compare(num)==0)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    cout<<endl;
    cout<<tmp<<endl;
        
    return 0;
}

