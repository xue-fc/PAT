#include<iostream>
#include<vector>

using namespace std;

int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        vector<int> l(n);
        vector<bool> isE(n,false);
        bool flag1 = true;
        for(int j=0;j<n;j++){
            cin>>l[j];
            if(isE[l[j]]){
                cout<<"NO\n";
                flag1 = false;
            }
            else{
                isE[l[j]]=true;
            }
        }
        if(!flag1)
            continue;
        bool flag=true;
        for(auto it=l.begin();it!=l.end();it++){
            if(!flag)
                break;
            for(auto lit=it+1;lit!=l.end();lit++){
                if(lit-it == *it-*lit || lit-it==*lit-*it){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"NO\n";
        }
        else
            cout<<"YES\n";
    }
    return 0;
}