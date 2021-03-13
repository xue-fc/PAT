/*
    极为麻烦，需要记录路径是属于哪条线的，不能记录节点
    这也是图算法的一个要点，判断某个性质是在节点上还是边上，比如权重和颜色等
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

bool isprime(int n){
    if(n<=1)
        return false;
    if(n==2 || n==3)
        return true;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int Msize,N,M;
    cin>>Msize>>N>>M;
    while(!isprime(Msize)){
        Msize++;
    }
    vector<int> hashTable(Msize,-1);
    vector<bool> isOcup(Msize,false);
    // int space=Msize;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        int q=1;
        int pos=tmp%Msize;
        while(isOcup[pos] && q<Msize){
            pos = (pos+q*q)%Msize;
            q++;
        }
        if(q<Msize-1){
            isOcup[pos]=true;
            hashTable[pos]=tmp;
        }else{
            printf("%d cannot be inserted.\n",tmp);
        }
    }
    int cnt=0;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        int pos = tmp%Msize;
        int q=1;
        bool find=false;
        while(isOcup[pos] && q<=Msize){
            // cnt++;
            if(hashTable[pos]==tmp){
                find=true;
                break;
            }else{
                pos = (pos+q*q)%Msize;
                q++;
            }
        }
        cnt+=q;
    }
    printf("%.1f\n",(float)cnt/M+0.05);
    return 0;
}
