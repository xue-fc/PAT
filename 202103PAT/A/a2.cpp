#include<iostream>
#include<vector>
using namespace std;

bool isprime(int n){
    if(n<=1)
        return false;
    if(n==2 || n==3)
        return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
bool all[200010];
vector<int> primes;
int main(){
    int n,upper;
    cin>>n>>upper;
    for(int i=2;i<=upper;i++){
        if(isprime(i))
        {
            all[i] = true;
            primes.push_back(i);
        }
    }
    // if(n==2 || n==1){
    //     return 0;
    // }
    vector<int> res;
    for(auto it=primes.begin();it!=primes.end();it++){
        vector<int> tmp;
        tmp.push_back(*it);
        for(auto lit=it+1;lit!=primes.end();lit++){
            tmp.push_back(*lit);
            for(int i=2;i<n;i++){
                if(all[*it + i*(*lit-*it)])
                    tmp.push_back(*it + i*(*lit-*it));
                else
                    break;
            }
            if(tmp.size()==n){
                if(res.size()==0)
                    res=tmp;
                else if(tmp[1]-tmp[0] >= res[1]-res[0]){
                    res = tmp;
                }
                // else if(tmp[1]-tmp[0]==res[1]-res[0])
            }
            else{
                tmp.clear();
                tmp.push_back(*it);
            }
        }
        tmp.clear();
    }
    if(res.size()!=0){
        cout<<res[0];
        for(auto it=res.begin()+1;it!=res.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    else{
        cout<<*(primes.end()-1)<<endl;
    }
    return 0;
}