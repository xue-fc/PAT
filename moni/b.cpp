#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> primes;
bool isprime(int a){
    if(a<=1)
        return false;
    if(a==2 || a==3)
        return true;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)
            return false;
    }
    return true;
}
bool p[20000000];
int is(int a){
    auto it=upper_bound(primes.begin(),primes.end(),a);
    if(it==primes.begin())
        return -1;
    if(*it==a){
        auto it1=it-1;
        auto it2=it+1;
        while(it1!=primes.begin() && it2!=primes.end()){
            if(*it1+*it2 == *it * 2){
                return a;
            }
        }
        return -1;
    }
    else{
        while(*it < *(primes.end()-1)){
            auto it1=it-1;
            auto it2=it+1;
            while(it1!=primes.begin() && it2!=primes.end()){
                if(*it1+*it2 == *it * 2){
                    return *it;
                }
            }
        }
        return -1;
    }
    return -1;
}
int main(){
    fill(p,p+20000000,false);
    primes.push_back(2);
    for(int i=3;i<20000000;i=i+2){
        if(isprime(i))
        {
            primes.push_back(i);
            p[i] = true;
        }
    }
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        int res = is(tmp);
        if(res==tmp){
            cout<<"Yes\n";
        }
        else 
            cout<<"No "<<res<<endl;
    }
    return 0;
}