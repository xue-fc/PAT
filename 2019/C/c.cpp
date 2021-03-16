#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main(){
    int tsize,m,n;
    cin>>tsize>>m>>n;
    vector<int> table(tsize,-1);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        int id = tmp%m;
        while(table[id]!=-1) id = (id+1)%tsize;
        table[id] = tmp;    
    }
    int num=0;
    for(int id=0;id<m;id++){
        int tmp=id;
        while(tmp!=(id+tsize-1)%tsize && table[tmp]!=-1)      tmp = (tmp+1)%tsize;
        num += (tmp==(id+tsize-1)%tsize ? tsize+1 : (tmp+tsize-id)%tsize+1);
    }
    double ave = (double)num/(double)m;
    printf("%.1lf",ave);
    return 0;
}