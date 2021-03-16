#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool isprime(unsigned long long a){
    if(a<=1)
        return false;
    if(a==2 || a==3)
        return true;
    for(long long i=2;i*i<=a;i++){
        if(a%i == 0)
            return false;
    }
    return true;
}

int main(){
    int N;
    cin>>N;
    if(N==1)
    {
        printf("1\nNo\n");
    }
    vector<int> factor;
    for(int i=2;i<=N;){
        if(N==1)
            break;
        if(N%i==0){
            factor.push_back(i);
            N = N/i;
        }
        else
            i++;
    }
    string res = "";
    int last = N;
    int num=1;
    for(auto it=factor.begin();it!=factor.end();it++){
        if(*it==last){
            num++;
        }
        else{
            if(num!=1){
                res = res + to_string(num);
                num = 1;
            }
            res = res + to_string(*it);
            last = *it;
        }
    }
    if(num!=1)
        res = res+to_string(num);
    cout<<res<<endl;
    unsigned long long n = stoull(res);
    if(isprime(n)) {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}