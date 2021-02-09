/*
    有1分没过，一个超时了
    初步思路是在知道3*4*5*6可以后，别再从4开始了，直接把三乘到余数上，然后从4*5*6继续
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
    long long n;
    cin>>n;
    int l=0;
    int maxl=0;
    vector<long long> maxf(0);
    long long i=2;
    while(i<n/2){    
        if(n%i==0){
            long long t=n;
            long long j=i;
            vector<long long> tmp;
            while(t%j==0 && t!=0)
            {
                t=t/j;
                tmp.push_back(j);
                j++;
            }
            if(tmp.size()>maxf.size())
                maxf=tmp;
        }
        i++;        
    }
    if(maxf.size()>0)
    {
        printf("%d\n",maxf.size());
        printf("%lld",maxf[0]);
        for(int i=1;i<maxf.size();i++)
            printf("*%lld",maxf[i]);
    }
    else{
        printf("1\n%d\n",n);
    }
    return 0;
}
