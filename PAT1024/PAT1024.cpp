#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000;
bool is_pnum(long long n);
int main(){
    long long N,K,i;
    cin>>N>>K;
    for(i=0;i<K;i++){
        if(is_pnum(N))
            break;
        else
        {
            string t = to_string(N);
            reverse(t.begin(),t.end());
            N = atoi(t.c_str()) + N;
        } 
    }
    cout<<N<<endl<<i<<endl;
    return 0;
}

bool is_pnum(long long n){
    string a = to_string(n);
    string b = to_string(n);
    reverse(b.begin(),b.end());
    return !a.compare(b);
}