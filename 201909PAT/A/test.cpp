#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int prime[13] = {3,5,7,11,13,17,19,23,29,31,37,41,43};
unordered_set<int> s(prime,prime+13);

bool isOk(int m,int n){
    int a = m>n ? m : n;
    int b = m>n ? n : m;
    int yushu = a%b;
    while(a%b!=0){
        int tmp=a;
        a = b;
        b = tmp%b;
    }
    if(s.count(b)!=0)
        return true;
    else
        return false;
}

bool isprime(int a){
    if(a==2 || a==3)
        return true;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)
            return false;
    }
    return true;
}

int main(){
    for(int i=1;i<100;i++)
    {
        if(isprime(i))
            cout<<i<<endl;
    }

    return 0;
}