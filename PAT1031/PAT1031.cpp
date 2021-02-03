/*
    比较简单，反向迭代器的用法
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

int main(){
    char str[MAX];
    cin.getline(str,MAX);
    string a = string(str);
    string b = string(str);
    string::iterator it = a.begin();
    string::reverse_iterator rit = a.rbegin();
    int l = a.length();
    int n = 0;
    while(n<l){
        l -= 2;
        n++;
    }
    n--;
    for(int i=0;i<n;i++){
        cout<<*it;
        for(int j=0;j<l;j++){
            cout<<' ';
        }
        cout<<*rit<<endl;
        it++;rit++;
    }
    for(int i=0;i<l+2;i++){
        cout<<*it;
        it++;
    }
    cout<<endl;

    return 0;
}
