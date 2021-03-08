#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<n<<endl;
        return 0;
    }
    int sum=0;
    int last=10000000;
    int tmp;
    int cnt=0;
    int last_min=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp <= last){
            v.insert(v.begin(),tmp);
            last = tmp;
        }
        else{
            int local=v[0];
            int last_weight=200;
            for(auto it=v.begin();it!=v.end();it++){
                if(*it > local){
                    last_weight += 100;
                    sum+=last_weight;
                }
                else{
                    sum+=last_weight;
                }
            }
            if(last_weight<=last_min){
                sum += last_min-last_weight+100;
                if(v.size()==1)
                    last_min = 300 + last_min - last_weight;
                else
                    last_min = 200;
            }
            else{
                last_min = 200;
            }
            v.clear();
            v.insert(v.begin(),tmp);
            last = tmp;
        }
    }
    // last_min=0;
    int local=v[0];
    int last_weight=200;
    for(auto it=v.begin();it!=v.end();it++){
        if(*it > local){
            last_weight += 100;
            sum+=last_weight;
        }
        else{
            sum+=last_weight;
        }
    }
    if(last_weight<=last_min){
        sum += v.size()*(last_min-last_weight+100);
        last_min = 300 + last_min - last_min;
    }
    else{
        last_min = 200;
    }
    v.clear();
    cout<<sum<<endl;
    return 0;
}