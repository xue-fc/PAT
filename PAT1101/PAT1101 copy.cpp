/*
    遍历两遍用两个数组存从左边到当前位置的最大值和从右边到当前位置的最小值，思路是这样
    很容易超时，如果vector长度已知，那就在构造函数那里直接写好大小。不然在插入时自动扩容会很慢
    容易超时的题换成scanf和printf进行IO操作，long long的占位符是%lld
    vector连续存储，可以和list对比下
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
    int n;
    scanf("%d",&n);
    long long tmp;
    long long max=-1,min=1000000000;
    int max_pos,min_pos;
    vector<long long> l(n);
    vector<long long> maxl(n),minl(n);
    vector<long long> res;
    for(int i=0;i<n;i++){
        scanf("%lld",&tmp);
        if(tmp > max)
        {
            max = tmp;
            max_pos = i;
        }
        maxl[i]=max;
        l[i]=tmp;
    }
    for(int i=l.size()-1;i>=0;i--){
        if(l[i]<min){
            min = l[i];
            min_pos = i;
        }
        minl[i] = min;
    }
    for(int i=min_pos;i<=max_pos;i++){
        if(l[i]>=maxl[i] && l[i]<=minl[i])
            res.push_back(l[i]);
    }
    printf("%d\n",res.size());
    for(int i=0;i<res.size();i++){
        if(i==0)
            printf("%lld",res[i]);
        else{
            printf(" %lld",res[i]);
        }
    }
    cout<<endl;
    return 0;
}
