#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

bool isp(int a){
    if(a<=1) return false;
    int sqr = (int)sqrt(a);
    for(int i=2;i<=sqr;i++){
        if(a%i==0) return false;
    }
    return true;
}

int main(){
    int a=1,b=2,c=0,d;
    vector<int> se;
    while (1){
        scanf("%d %d",&a,&b);
        while(a!=0){
            d=a%b;
            se.push_back(d);
            a=a/b;
        }
        for(int i=0;i<se.size();i++){
            int x=se[i];
            printf("%d",se.size()-i-1);
            c+=x*b^(se.size()-i-1);
        }

        if(isp(c)) printf("Yes\n");
        else printf("No\n");
        c=0;  
        se.clear();     
    }
    
    
    return 0;
}