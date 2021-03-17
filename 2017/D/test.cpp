#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> t(10);
    if(n<50){
        fill(t.begin(),t.begin()+10000,1);
    }
    return 0;
}