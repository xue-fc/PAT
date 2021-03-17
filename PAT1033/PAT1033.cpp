#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;

map<int,double> m;

int main(){
    int Cmax,D,Davg,N;
    cin>>Cmax>>D>>Davg>>N;
    for(int i=0;i<N;i++){
        double p;
        int d;
        cin>>p>>d;
        m[d] = p;
    }

    return 0;
}
