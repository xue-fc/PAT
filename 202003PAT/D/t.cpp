#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
    int N,M,last;
    cin>>N>>M;
    vector<int> memory(M);
    int cnt=0;
    for(int i=0;i<M && cnt<N;i++,cnt++){
        int tmp;
        scanf("%d",&tmp);
        memory[i]=tmp;
    }
    sort(memory.begin(),memory.end());
    int l=M;
    bool flag;
    while(cnt<N){
        l=M;
        last=-(1<<30);
        flag=true;
        while(cnt<N){   
            if(memory[M-l]<last)
            {
                l--;
                if(l==0)
                    break;
            }
            int tmp;
            scanf("%d",&tmp);
            cnt++;
            if(flag)
            {
                printf("%d",memory[M-l]);
                flag = false;
            }else{
                printf(" %d",memory[M-l]);
            }

            last = memory[M-l];
            memory.erase(memory.begin()+M-l);
            auto it=memory.begin();
            for(;it!=memory.begin()+l;it++){
                if(tmp<*it){
                    memory.insert(it,tmp);
                    break;
                }
            }
            if(it==memory.begin()+l)
                memory.push_back(tmp);
        }
        if(l==0){
            printf("\n");
        }
    }
    if(memory[M-l]<last)
        l--;
    for(int i=M-l;i<M;i++){
        if(flag)
            {
                printf("%d",memory[i]);
                flag = false;
            }else{
                printf(" %d",memory[i]);
            }
    }
    flag = true;
    memory.erase(memory.begin()+M-l,memory.end());
    if(!memory.empty())
    {   
        sort(memory.begin(),memory.end());
        printf("\n%d",memory[0]);
        for(auto it=memory.begin()+1;it!=memory.end();it++){
            printf(" %d",*it);
        }
            printf("\n");
    }
    
    return 0;
}