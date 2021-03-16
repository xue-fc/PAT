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

bool all[100010];

int main(){
    fill(all,all+100010,false);

    int n,upper;
    cin>>n>>upper;
    for(int i=2;i<upper;i++){
        all[i] = isprime(i);
    }
    int i=1,j=upper;
    bool flag = true;
    while(!all[j]) j--;
    int maxP = j;
    vector<int> res;
    while(j-i>n){
        if(flag)
            while(!all[i]) i++;
        else
            while(!all[j]) j--;
        if(j-i % n ==0){
            int step = (j-i)/n;
            int cnt;
            vector<int> tmp;
            for(cnt=0;cnt<n;cnt++){
                tmp.push_back(i+step*cnt);
                if(!all[i+step*cnt])
                    break;
            }
            if(cnt==n){
                res = tmp;
            }
        }
        flag = !flag;
        if(flag)
            i++;
        else
            j--;
    }
    if(res.size()!=0){
        cout<<res[0];
        for(auto it=res.begin()+1;it!=res.end();it++){
            cout<<" "<<res[i];
        }
        cout<<endl;
    }
    else
        cout<<maxP<<endl;
    return 0;

}