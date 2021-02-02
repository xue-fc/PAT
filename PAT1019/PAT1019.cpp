#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
vector<int> d2r(int num,int radix);
int main(){
    int num,radix;
    cin>>num>>radix;
    if(num==0){
        cout<<"Yes\n0\n";
        return 0;
    }
    vector<int> n = d2r(num,radix);
    vector<int> rn = vector<int>(n);
    reverse(n.begin(),n.end());
    vector<int>::iterator it1=n.begin(),it2=rn.begin();
    while(it1!=n.end() && it2!=rn.end()){
        if(*it1 != *it2){
            cout<<"No"<<endl;
            break;
        }
        it1++;it2++;
    }
    if(it1 == n.end())
        cout<<"Yes"<<endl;
    for(it1=n.begin();it1!=n.end();it1++){
        cout<<*it1;
        if(n.end() - it1 != 1)
            cout<<' ';
    }
    cout<<endl;
    return 0;
}

vector<int> d2r(int num,int radix){
    vector<int> t;
    while(num!=0){
        t.push_back(num % radix);
        num = num / radix;
    }
    return t;
}

