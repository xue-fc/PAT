#include<iostream>

using namespace std;

bool isPrime(int n){
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

int findPair(int n){
    if(!isPrime(n))
        return -1;
    // if(isPrime(n-6)){
    //     // cout<<"Yes\n"<<n-6<<endl;
    //     return n-6;
    // }
    if(isPrime(n+6)){
        // cout<<"Yes\n"<<n+6<<endl;
        return n+6;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    if(isPrime(n)){
        if(isPrime(n-6)){
            cout<<"Yes\n"<<n-6<<endl;
            return 0;
        }
        else if(isPrime(n+6)){
            cout<<"Yes\n"<<n+6<<endl;
            return 0;
        }
    }
    cout<<"No\n";
    for(int i=n-5;;i++){
        int a = findPair(i);
        if(a!=-1){
            cout<<(i>n ? i : i+6)<<endl;
            return 0;
        }
    }

    return 0;
}