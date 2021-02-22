/*
    注意判断是否为质数时要单独判断0和1的
    循环的起始条件要认真推一下
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<math.h>
using namespace std;

const int MAX = 1000;
typedef unsigned long long ull;
bool isprime(ull n);
int main(){
    int k,n;
    string l,tmp;
    cin>>n>>k>>l;
    for(string::iterator it=l.begin();it!=l.end()-k+1;it++){
        tmp = string(it,it+k);
        ull n = stoull(tmp);
        if(isprime(n)){
            cout<<tmp<<endl;
            return 0;
        }
    }
    cout<<"404"<<endl;
    return 0;
}
bool isPrime(ull n) {
    if (n == 0 || n == 1) return false;
    for (ull i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}