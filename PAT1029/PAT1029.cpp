//用cin.getline()再加字符串处理一个是容易越界，比如这题里MAX等于十万都不够；另一个是处理字符串慢
//没有这个必要，就循环加cin吧
//此外erase批量删除的接口可以看下（删除后对迭代器的影响也看看）
//merge的API

#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 100000;

int main(){
    char str[MAX],*token;
    vector<long long> a,b;
    int num,all=0;
    cin>>num;
    for(int i=0;i<num;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    getchar();
    cin>>num;
    for(int i=0;i<num;i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int la=a.size(),lb=b.size();        

    vector<long long> t(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),t.begin());
    cout<<t[(t.size()-1)/2]<<endl;

    return 0;
}
