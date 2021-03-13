#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
int prime[] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

unordered_set<int> s(prime,prime+13);

bool isOk(int m,int n){
    int a = m>n ? m : n;
    int b = m>n ? n : m;
    int yushu = a%b;
    while(a%b!=0){
        int tmp=a;
        a = b;
        b = tmp%b;
    }
    if(s.count(b)!=0)
        return true;
    else
        return false;
}

int sum(const string &a){
    int n=0;
    for(auto it=a.begin();it!=a.end();it++){
        n += *it-'0';
    }
    return n;
}
map<int,vector<string>> res;
string num="";
int K,m;

void helper(int depth){
    if(9*(K-depth)+sum(num) < m)
        return;
    for(int cnt=0;cnt<=9;cnt++){
        if(cnt==0 && depth==1)
            continue;
        num[depth] = '0'+cnt;
        if(depth == K-1)
        {
            if(sum(num) == m){
                int tmp = sum(to_string(stoi(num)+1));
                // cout<<tmp;
                if(res.count(tmp) != 0){
                    res[tmp].push_back(num);
                }
            }
        }
        else{
            helper(depth+1);
        }
        // num.erase(num.end()-1);
    }
}

int main(){
    int N;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++){
        printf("Case %d\n",i+1);
        cin>>K>>m;
        res.clear();
        for(int j=3;j<=m+1;j++){
            if(isOk(m,j)){
                res[j] = vector<string>();
            }
        }
        for(int cnt=0;cnt<K;cnt++){
            num = num + "0";
        }
        helper(0);
        bool flag=false;
        for(auto it=res.begin();it!=res.end();it++){
            if((it->second).empty())
                continue;
            sort(it->second.begin(),it->second.end());
            for(auto lit=it->second.begin();lit!=it->second.end();lit++)
            {
                flag = true;
                printf("%d %s\n",it->first,(*lit).c_str());
            }
        }
        if(!flag){
            printf("No Solution\n");
        }
    }

    return 0;
}