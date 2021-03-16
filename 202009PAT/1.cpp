#include<iostream>
#include<queue>
#include<math.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<cmath>
using namespace std;
int n;
int pandas[10001]={};
int main(){
    int former=100;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>pandas[i];
    pandas[0]=-1;
    int left=1,right=2;
    int left_milk,right_milk;
    while(right<=n)
    {
        if(pandas[right-1]>pandas[right])
        right++;
        else
        {
            if(pandas[left]>pandas[left-1])
            left_milk=max(former+100,200+100*(right-left-1));
            else
            left_milk=max(former,200+100*(right-left-1));
            right_milk=left_milk-100*(right-left-1);
            sum+=(left_milk+right_milk)*(right-left)/2;
            left=right;
            former=right_milk;
            right++;
        }
    }
    if(pandas[left]>pandas[left-1])
    left_milk=max(former+100,200+100*(right-left-1));
    else
    left_milk=max(former,200+100*(right-left-1));
    right_milk=left_milk-100*(right-left-1);
    sum+=(left_milk+right_milk)*(right-left)/2;
    cout<<sum<<endl;
    return 0;
}