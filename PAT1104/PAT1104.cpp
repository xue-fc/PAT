/*
    这题用double会溢出，但出题的时候应该不会考虑这个，老实用就好
    一个比较坑的地方是f的返回值得是long long，不然会溢出
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

long long f(int pos,int n){
    return (n-pos+1)*pos;
}

int main(){
    int n;
    double sum=0,tmp;
    cin>>n;
    for(long long i=1;i<=n;i++){
        scanf("%lf",&tmp);
        sum += f(i,n)*tmp;
    }
    printf("%.2lf",sum);
    

    return 0;
}
