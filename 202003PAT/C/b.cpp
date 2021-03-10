#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
    int N,R,K;
    cin>>N>>R>>K;
    // vector<pair<int,int>> relations;
    vector<int> ra(R),rb(R);
    for(int i=0;i<R;i++){
        int a,b;
        cin>>a>>b;
        ra[i] = a;
        rb[i] = b;
    }
    int M;
    cin>>M;

    for(int i=0;i<M;i++){
        set<int> species;
        vector<int> dis(N);
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            dis[j]=tmp;
            species.insert(tmp);
        }
        if(species.size()>K){
            cout<<"Error: Too many species.\n";
        }
        else if(species.size()<K){
            cout<<"Error: Too few species.\n";
        }
        else{
            int cnt;
            for(cnt=0;cnt<ra.size();cnt++){
                if(dis[ra[cnt]-1]==dis[rb[cnt]-1]){
                    cout<<"No\n";
                    break;
                }
            }
            if(cnt==ra.size()){
                cout<<"Yes\n";
            }
        }
    }
    return 0;
}