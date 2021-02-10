/*
    题目容易理解错
    排序即可，不算难
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
typedef long long LL;

int main(){
    LL n,tmp,i,sum=0,max=0;
    vector<LL> v(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    LL last=0;
    vector<LL>::iterator it=v.begin();
    for(LL i=0;i<v[v.size()-1];i++){
        while(i >= *it)
            it++;
        if(v.end()-it >= i)
            max = i;
        else
            break;
    }
    cout<<max<<endl;
    return 0;
}
