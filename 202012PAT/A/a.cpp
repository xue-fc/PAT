#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;

    int a=1,b=1;
    int c,tmp;
    while(1){
        if(b>N){
            break;
        }
        c=a+b;
        a = b;
        b = c;
    }
    if(N-a > b-N){
        cout<<b<<endl;
    }
    else{
        cout<<a<<endl;
    }
}