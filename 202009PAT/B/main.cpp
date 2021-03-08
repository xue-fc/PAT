#include<iostream>
#include<vector>

using namespace std;
int main(){
    int N,M;
    int res=0;
    cin>>N>>M;
    vector<int> price(N);
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d",&tmp);
        price[i]=tmp;
    }
    for(int i=0;i<N;i++){
        int sum=price[i];
        int j=i+1;
        while(M>=sum){
            res++;
            if(j>=N)
                break;
            sum = sum+price[j];
            j++;
        }
    }
    cout<<res<<endl;
    return 0;
}