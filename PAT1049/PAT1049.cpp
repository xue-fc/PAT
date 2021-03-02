/*
    排序而已，比较简单，注意调整两个vector的长度即可
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
    char str[MAX];
    scanf("%s",str);
    string num = string(str);
    reverse(num.begin(),num.end());
    int res=0;
    int last=1;
    int carry=1;
    while(num.size()!=0){
        // res = carry + 
    }
    return 0;
}
