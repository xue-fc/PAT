#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

const int MAX = 10000;

vector<int> decimalto(int n,int r);
int todecimal(vector<int> n,int r);
bool isprime(int n);

int main(){
    int num,radix;
    vector<int> t;
    while (1)
    {
        cin>>num;
        if(num<0) break;
        cin>>radix;
        if(!isprime(num)){
            cout<<"No"<<endl;
            continue;
        }
        vector<int> number = decimalto(num,radix);
        reverse(number.begin(),number.end());
        int res = todecimal(number,radix);
        t.push_back(res);
    }
    for(vector<int>::iterator it=t.begin();it!=t.end();it++)
        cout<<(isprime(*it) ? "Yes" : "No")<<endl;

    return 0;
}

bool isprime(int n){
    if(n==1)
        return false;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

vector<int> decimalto(int n,int r){
    int t=0;
    vector<int> res;
    while(n!=0){
        res.push_back(n%r);
        n = n / r;
    }
    return res;
}

int todecimal(vector<int> n,int r){
    int res=0,tmp=1;
    for(vector<int>::iterator it=n.begin();it!=n.end();it++){
        res += tmp * (*it);
        tmp *= r;
    }
    return res;
}
