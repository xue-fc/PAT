/*
    注意用scanf和printf，以防超时
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

struct person{
    string name;
    int age;
    int worth;
};

bool cmp(const person &a,const person &b){
    if(a.worth != b.worth)
        return a.worth > b.worth;
    else{
        if(a.age != b.age)
            return a.age < b.age;
        else
        {
            return a.name < b.name;
        }
        
    }
}

int main(){
    int N,K;
    scanf("%d",&N);
    scanf("%d",&K);
    vector<person> a(N);
    for(int i=0;i<N;i++){
        char str[MAX];
        int b;
        scanf("%s",str);
        a[i].name = string(str);
        scanf("%d",&b);
        a[i].age = b;
        scanf("%d",&b);
        a[i].worth = b;
    }

    sort(a.begin(),a.end(),cmp);
    
    for(int i=1;i<=K;i++){
        int M,low,high;
        bool flag = false;
        scanf("%d",&M);
        printf("Case #%d:\n",i);
        if(M==0){
            printf("None\n");
        }
        scanf("%d",&low);
        scanf("%d",&high);
        for(auto it=a.begin();it!=a.end();it++){
            if(it->age>=low && it->age<=high){
                flag = true;
                printf("%s %d %d\n",it->name.c_str(),it->age,it->worth);
                M--;
                if(M==0)
                    break;
            }
        }
        if(!flag)
            printf("None\n");
    }
    return 0;
}
