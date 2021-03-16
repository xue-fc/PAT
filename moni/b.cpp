#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N+1);
    v[0] = 999999;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        v[i]=tmp;
        int c = i;
        while(1){
            if(v[c] > v[c/2]){
                int a = v[c];
                v[c] = v[c/2];
                v[c/2] = a;
                c = c/2;
            }
            else
                break;
        }
    }
    for(auto it=v.begin()+1;it!=v.end();it++){
        if(it!=v.begin()+1)
            cout<<" ";
        cout<<*it;
    }
    cout<<endl;
    return 0;
}