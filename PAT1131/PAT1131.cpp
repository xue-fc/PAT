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
#include<unordered_map>
using namespace std;

const int MAX = 1000;



int main(){
    int N,M;
    scanf("%d",&N);
    vector<vector<int>> lines(N+1);
    unordered_map<int,int> dic;
    for(int i=1;i<=N;i++){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d",tmp);
            lines[i].push_back(tmp);
            // if(dic.count())
        }
    }

    scanf("%d",&M);

    return 0;
}
