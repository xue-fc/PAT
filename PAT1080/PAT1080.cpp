/*
    错误代码。
    注意在sort后数组或vector就全变了，不能用原来的下标
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

struct stu{
    int id;
    int ge,gi,g;
    int c[5];
    int rank;
}all[40015];

bool cmp(stu a,stu b){
    if(a.g!=b.g)return a.g>b.g;
    if(a.ge!=b.ge)return a.ge>b.ge;
    return a.id<b.id;
}

int admit[105][40015];

int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    int quota[105];for(int i=0;i<m;i++)scanf("%d",quota+i);
    for(int i=0;i<n;i++){
        all[i].id=i;
        scanf("%d%d",&all[i].ge,&all[i].gi);
        all[i].g=all[i].ge+all[i].gi;
        for(int j=0;j<k;j++)scanf("%d",&all[i].c[j]);
    }
    sort(all,all+n,cmp);
    for(int i=0;i<n;i++){
        if(i==0||all[i].g!=all[i-1].g||all[i].ge!=all[i-1].ge){
            all[i].rank=i+1;
        }
        else all[i].rank=all[i-1].rank;
    }
    int count[105]={0};
    int nowc;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            nowc=all[i].c[j];
            if(quota[nowc]==0)continue;
            if(count[nowc] < quota[nowc] || all[admit[nowc][count[nowc]-1]].rank==all[i].rank){
                admit[nowc][count[nowc]]=all[i].id;
                //这里的id是排序前的id，不能再用它当下标访问all了
                count[nowc]++;
                break;
            }
        }
    }
//    /*
    for(int i=0;i<m;i++){
        sort(admit[i],admit[i]+count[i]);
        if(count[i]==0){
            printf("\n");
            continue;
        }
        for(int j=0;j<count[i];j++){
            printf("%d",admit[i][j]);
            if(j==count[i]-1)break;
            printf(" ");
        }
        printf("\n");
    }
//    */
}
